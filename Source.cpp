#include <iostream>
#include <vector>
using namespace std;


class TreeType
{
private:
    string name;
    string color;
    string texture;

public:
    TreeType(string name="", string color="", string texture="")
        : name{ name }, color{ color }, texture{ texture } {}

    string getName() { return name; }
    string getColor() { return color; }
    string getTexture() { return color; }
};

class TreeFactory abstract
{
private:
    static vector<TreeType> treeTypes;

public:
    static TreeType getTreeType(string name, string color, string texture)
    {
        int size = treeTypes.size();
        for (int i = 0; i < size; i++)
            if (treeTypes[i].getName() == name && treeTypes[i].getColor() == color && treeTypes[i].getTexture() == texture)
                return treeTypes[i];
        treeTypes.push_back(TreeType(name, color, texture));
        return treeTypes.back();
    }
};
vector<TreeType> TreeFactory::treeTypes;

class Tree
{
private:
    int x, y;
    TreeType type;

public:
    Tree(int x, int y, TreeType type)
        : x{ x }, y{ y }, type{ type } {}

    void draw() { cout << "Draw!" << endl; }
};

class Forest
{
private:
    vector<Tree> trees;

public:
    void plantTree(int x, int y, string name, string color, string texture)
    {
        trees.push_back(Tree(x, y, TreeFactory::getTreeType(name, color, texture)));
    }
};

int main()
{
    Forest forest;
    forest.plantTree(0, 0, "tree1", "", "tree1.png");
    forest.plantTree(1, 0, "tree2", "", "tree2.png");
    forest.plantTree(0, 1, "tree3", "", "tree_texture3.png");
    forest.plantTree(1, 1, "tree1", "", "tree1.png");
    forest.plantTree(2, 2, "tree1", "", "tree1.png");

    return 0;
}
