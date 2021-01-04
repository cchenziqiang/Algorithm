#include <exception>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Pet {
 public:
  Pet(){};
  Pet(string ty) : type(ty) {}
  string getType() { return type; }

 private:
  string type;
};

class Dog : public Pet {
 public:
  Dog() : Pet("dog") {}
};
class Cat : public Pet {
 public:
  Cat() : Pet("cat") {}
};

class PetQueue {
 public:
  PetQueue() : p(nullptr), count(0) {}
  PetQueue(Pet* pPet, long num) : p(pPet), count(num) {}
  Pet* getPet() { return p; }
  long getCount() { return count; }
  string getPetType() { return p->getType(); }

 private:
  Pet* p;
  long count;
};

class DogCatQueue {
 public:
  DogCatQueue() : count(0) {}
  void add(Pet* p) {
    PetQueue* petq = new PetQueue(p, count++);
    if (p->getType() == "dog")
      DogQ.push(petq);
    else if (p->getType() == "cat")
      CatQ.push(petq);
    else
      throw new exception();
  }

  Pet* PollAll() {
    Pet* p;
    if (!(DogQ.empty() && CatQ.empty())) {
      if (DogQ.front()->getCount() < CatQ.front()->getCount()) {
        p = DogQ.front()->getPet();
        DogQ.pop();
        return p;
      } else {
        p = CatQ.front()->getPet();
        CatQ.pop();
        return p;
      }
    } else if (DogQ.empty()) {
      p = CatQ.front()->getPet();
      CatQ.pop();
      return p;
    } else if (CatQ.empty()) {
      p = DogQ.front()->getPet();
      DogQ.pop();
      return p;
    } else
      throw new exception();
  }
  Pet* pollDog() {
    if (DogQ.empty())
      throw new exception();
    else {
      Pet* p;
      p = DogQ.front()->getPet();
      DogQ.pop();
      return p;
    }
  }

  Pet* pollCat() {
    if (CatQ.empty())
      throw new exception();
    else {
      Pet* p;
      p = CatQ.front()->getPet();
      CatQ.pop();
      return p;
    }
  }

  bool isEmpty() { return DogQ.empty() && CatQ.empty(); }
  bool isCatEmpty() { return CatQ.empty(); }
  bool isDogEmpty() { return DogQ.empty(); }

 private:
  queue<PetQueue*> DogQ;
  queue<PetQueue*> CatQ;
  long count;
};

int main() {
  Pet* c1 = new Cat();
  Pet* c2 = new Cat();
  Pet* d1 = new Dog();
  Pet* d2 = new Dog();
  Pet* p;

  DogCatQueue* dcq = new DogCatQueue();
  dcq->add(c1);
  dcq->add(d1);
  p = dcq->pollDog();
  cout << p->getType() << endl;
  dcq->add(d2);
  dcq->add(d1);
  dcq->add(c2);
  p = dcq->pollCat();
  cout << p->getType() << endl;
  p = dcq->pollCat();
  cout << p->getType() << endl;
  dcq->add(c2);
  p = dcq->PollAll();
  cout << p->getType() << endl;
  p = dcq->PollAll();
  cout << p->getType() << endl;
}
