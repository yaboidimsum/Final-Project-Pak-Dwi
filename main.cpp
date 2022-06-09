#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
};

TreeNode* CreateNode(char data)
{
    TreeNode *newNode = (TreeNode*)malloc (sizeof(TreeNode));
    newNode->data  = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

char result(TreeNode *node, int age, string status, string job, string antusiasm)
{
    if (!node->left && !node->right)return node->data;

    if (node->data == 's')
    {
        if (status == "CEO's_grandchild") return result (node->left,age,status,job,antusiasm);
        else if (status == "CEO's__children") return result (node->mid, age, status, job, antusiasm);
        else return result (node->right,age,status,job,antusiasm);
    }
    else if (node->data == 'a')
    {
        if(age > 25) return result (node->left, age, status,job,antusiasm);
        return result(node->right,age,status,job,antusiasm);
    }
    else if (node->data == 'j')
    {
        if(job == "Employed") return result (node->left, age, status,job,antusiasm);
        return result(node->right,age,status,job,antusiasm);
    }
    else
    {
        if (antusiasm == "Yes")return result (node->left, age, status,job,antusiasm);
        return result (node->right,age,status,job,antusiasm);
    }
}


int main()
{
    ifstream file;
    ofstream file1;

    string data,status,job,antusiasm;
    int age;
    file.open("data.txt");
    file1.open("result.txt");
    getline(file, data);
    file1 << data << "\t" << "Result\n" ;

    TreeNode *root = CreateNode('s');
    root->mid = CreateNode('a');
    root->right = CreateNode('j');
    root->right -> left = CreateNode('n');
    root->left = root->mid->left = root->right->left->left = CreateNode('1');
    root->mid->right = root->right->right = root->right->left->right = CreateNode('0');

    while(!file.eof())
    {
        file >> age;
        file >> status;
        file >> job;
        file >> antusiasm;

        file1 << age << "\t" << status << "\t" << job << "\t" << antusiasm << "\t\t";
        if (result(root,age,status,job,antusiasm)== '1') file1 << "Bisa jadi CEO\n";
        else file1 << "Gak bisa jadi CEO\n";
    }
    file.close();
    file1.close();

    cin.get();

    return 0;
}
