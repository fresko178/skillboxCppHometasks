#include <iostream>
#include <vector>

constexpr int SIZE {5};

using std::cout;
using std::cin;
using std::endl;

class Branch { //    Достаточно одного класса Branch с такими атрибутами. Дерево это Branch с parent = null
public:
  Branch *parent = nullptr;
  std::vector<Branch *> children;
  std::string elfName = "None";
};

void setName(Branch *b) {
  cout << "Введите имя заселяемого эльфа: ";
  std::string name;
  std::cin >> name;
  if (name != "None") { b->elfName = name; }
}

void outputNeighbors(Branch *b) {
  cout << "обнаружен ельф " << b->elfName << endl;
  int countNeighbors {0};
  if (b->children.size() == 0) { // если это средняя ветвь
    for (size_t i {0}; i < b->parent->children.size(); i++) {
      if (b->parent->children[i]->elfName != "None") { countNeighbors++; }
    }
    countNeighbors--; // вычитаем найденного эльфа т.к. он не None
    if (b->parent->elfName != "None")  { countNeighbors++; } // не забываем про родителя
    cout << "общее кол. эльфов соседей = " << countNeighbors << endl;
  } else { // это основная ветвь
    for (size_t i {0}; i < b->children.size(); i++) {
        if (b->children[i]->elfName != "None") { countNeighbors++; }
    }
    cout << "общее кол. эльфов соседей = " << countNeighbors << endl;
  }
}

void search(Branch &tree ,std::string name) {
  for (int countTree {0}; countTree < SIZE; countTree++) { // список деревьев
    for (size_t i {0}; i < tree.children.size(); i++) { // проходим по основным веткам
      if (tree.children[i]->elfName == name) { // найден ельф на основной ветке
        outputNeighbors(tree.children[i]);
        return; // поиск окончен
      }
      for (size_t j {0}; j < tree.children[i]->children.size(); j++) { // проходим по средним веткам
        if (tree.children[i]->children[j]->elfName == name) { // найден ельф на средней ветке
          outputNeighbors(tree.children[i]->children[j]);
          return; // поиск окончен
        }
      }
    }
  }
}

int main()
{
  std::vector<Branch *> forest;
  int countMainBranch = std::rand() % 3 + 3; // 3 - 5 сатановский
  int countMiddleBranch = std::rand() % 2 + 2; // 2 - 3 средние ветки
  cout << "деревьев 5" << endl;
  cout << "основных веток " << countMainBranch << endl;
  cout << "средних веток " << countMiddleBranch << endl;
  for (int i {0}; i < SIZE; i++) {
    cout << endl << "дерево " << i << endl << endl;
    Branch *tree = new Branch();
    for (int i{0}; i < countMainBranch; i++) {
      cout << "основная ветка " << i << "  ";
      Branch *mainBranch = new Branch();
      setName(mainBranch);
      for (int i{0}; i < countMiddleBranch; i++) {
        cout << "    средняя ветка " << i << "  ";
        Branch *middleBranch = new Branch();
        setName(middleBranch);
        middleBranch->parent = mainBranch; // предков надо помнить
        mainBranch->children.push_back(middleBranch);
      }
      mainBranch->parent = tree;
      tree->children.push_back(mainBranch);
    }
    forest.push_back(tree);
  }

  cout << endl << "Введите имя искомого эльфа: ";
  std::string name;
  cin >> name;
  for (size_t i {0}; i < SIZE; i++) {
    search(*forest[i], name);
  }

  return 0;
}
