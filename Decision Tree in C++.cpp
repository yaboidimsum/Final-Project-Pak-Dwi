#include <bits/stdc++.h>


using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
};

TreeNode* create_node(char data)
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
            //Else thinking method such as Analitis,Abstrak,konkrit,dan konvergen
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
    ifstream file_data;
    ofstream file_result;

    string data,jurusan,personalitas,thinking_method;
    int skor;

    file_data.open("data.txt");
    file_result.open("result.txt");
    getline(file_data, data);
    file_result << data << "\t" << "Result\n" ;

    TreeNode *root = create_node('f');
    root->mid = create_node('s');
    root->right = create_node('j');
    root->right -> left = create_node('n');

    //Buat ngasi tau pattern sesuai kondisi if else di char result
    //Sesuai arah dari tree
    root->left = root->mid->left  = root->right->left->left = create_node('1');
    root->mid->right = root->right->right = root->right->left->right = create_node('0');

    while(!file_data.eof())
    {
        file_data >> skor;
        file_data >> jurusan;
        file_data >> thinking_method;
        file_data >> personalitas;

        file_result << skor << "\t" << jurusan << "\t" << personalitas << "\t" << thinking_method << "\t\t";
        if (result(root,skor,jurusan,thinking_method,personalitas)== '1')
        file_result << "CREABIZ ITS\n";
        else file_result << "FSAD ITS atau FTEIC ITS \n";
    }

    file_data.close();
    file_result.close();

    cin.get();

    return 0;
}



