#include <bits/stdc++.h>


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
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

char result(TreeNode *node, int skor, string jurusan, string thinking_method, string personalitas)
{
    if (!node->left && !node->right)return node->data;

    if (node->data == 'f')
    {
        if(thinking_method == "Kreatif")
            return result (node->left, skor, jurusan,thinking_method,personalitas);
        else if (thinking_method == "Logika")
            return result (node->mid, skor, jurusan, thinking_method, personalitas);
        return result(node->right,skor,jurusan,thinking_method,personalitas);
    }

    else if (node->data == 's')
    {
        if(skor < 600)
            return result (node->left, skor, jurusan,thinking_method,personalitas);
        return result(node->right,skor,jurusan,thinking_method,personalitas);
    }

    else if (node->data == 'j')
    {
        if (jurusan == "IPS")
            return result (node->left,skor,jurusan,thinking_method,personalitas);
        else return result (node->right,skor,jurusan,thinking_method,personalitas);
    }
    else
    {
        if (personalitas == "Extrovert")
            return result (node->left, skor, jurusan,thinking_method,personalitas);
        return result (node->right,skor,jurusan,thinking_method,personalitas);
    }
}


int main()
{
    ifstream file;
    ofstream file1;

    string data,jurusan,personalitas,thinking_method;
    int skor;

    file.open("data.txt");
    file1.open("result.txt");
    getline(file, data);
    file1 << data << "\t" << "Result\n" ;

    TreeNode *root = CreateNode('f');
    root->mid = CreateNode('s');
    root->right = CreateNode('j');
    root->right -> left = CreateNode('n');

    //Buat ngasi tau pattern sesua kondisi if else di char result
    //Sesuai arah dari tree
    root->left = root->mid->left = root->right->left->left = CreateNode('1');
    root->mid->right = root->right->right = root->right->left->right = CreateNode('0');

    while(!file.eof())
    {
        file >> skor;
        file >> jurusan;
        file >> thinking_method;
        file >> personalitas;

        file1 << skor << "\t" << jurusan << "\t" << personalitas << "\t" << thinking_method << "\t\t";
        if (result(root,skor,jurusan,thinking_method,personalitas)== '1')
        file1 << "CREABIZ ITS/FSRD ITB\n";
        else file1 << "FSAD ITS/FMIPA ITB atau FTEIC ITS/STEI ITB\n";
    }

    file.close();
    file1.close();

    cin.get();

    return 0;
}



