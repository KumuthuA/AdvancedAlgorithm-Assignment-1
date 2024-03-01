#include "BST.h"
#include "RBTree.h"
#include "SplayTree.h"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <chrono>
// #include <vector>

// using namespace std;
// using namespace chrono;

// int main()
// {
//     BST bst;

//     ifstream inputFile("data/data/insert/set1/data_1.txt");

//     if (!inputFile.is_open())
//     {
//         cerr << "Error: Unable to open data file." << endl;
//         return 1;
//     }
//     auto start = high_resolution_clock::now();

//     string line;
//     while (getline(inputFile, line))
//     {
//         stringstream next_line(line);
//         string number_str;

//         while (getline(next_line, number_str, ','))
//         {
//             long long int number = stoll(number_str);
//             bst.put(number, number);
//         }
//     }
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);

//     inputFile.close();

//     bst.print_in_order();
//     cout << "Time spent for insertion: " << duration.count() << " microseconds" << endl;
// }

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertBST(BST &bst, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            bst.put(number, number);
        }
    }
}

void searchBST(BST &bst, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            bst.get(number);
        }
    }
}

void insertSplayTree(SplayTree &splayTree, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            splayTree.put(number, number);
        }
    }
}

void searchSplayTree(SplayTree &splayTree, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            splayTree.contains(number);
        }
    }
}

void insertRedBlackTree(RBTree &rbTree, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            rbTree.put(number, number);
        }
    }
}

void searchRedBlackTree(RBTree &rbTree, ifstream &inputFile)
{
    string line;
    while (getline(inputFile, line))
    {
        stringstream next_line(line);
        string number_str;

        while (getline(next_line, number_str, ','))
        {
            long long int number = stoll(number_str);
            rbTree.get(number);
        }
    }
}

int main()
{

    for (int set = 1; set <= 2; ++set)
    {
        for (int i = 1; i <= 3; ++i)
        {

            BST bst;
            SplayTree splayTree;
            RBTree rbTree;

            string fileName = "data/data/insert/set" + to_string(set) + "/data_" + to_string(i) + ".txt";
            string searchFileName = "data/data/search/set" + to_string(set) + "/data_" + to_string(i) + ".txt";

            ifstream inputFile(fileName);
            ifstream searchFile(searchFileName);

            if (!inputFile.is_open())
            {
                cerr << "Error: Unable to open data file: " << fileName << endl;
                return 1;
            }

            if (!searchFile.is_open())
            {
                cerr << "Error: Unable to open search file: " << searchFileName << endl;
                return 1;
            }

            cout << "For dataset 'set" << set << "', data_" << i << ".txt:" << endl;
            cout << endl;

            auto start_bst = high_resolution_clock::now();
            insertBST(bst, inputFile);
            auto stop_bst = high_resolution_clock::now();
            auto duration_bst = duration_cast<microseconds>(stop_bst - start_bst);
            inputFile.close();

            cout << "BST insertion time: " << duration_bst.count() << " microseconds" << endl;

            auto start_search_bst = high_resolution_clock::now();
            searchBST(bst, searchFile);
            auto stop_search_bst = high_resolution_clock::now();
            auto duration_search_bst = duration_cast<microseconds>(stop_search_bst - start_search_bst);
            searchFile.close();

            cout << "BST search time: " << duration_search_bst.count() << " microseconds" << endl;
            cout << endl;

            inputFile.open(fileName);
            auto start_splaytree = high_resolution_clock::now();
            insertSplayTree(splayTree, inputFile);
            auto stop_splaytree = high_resolution_clock::now();
            auto duration_splaytree = duration_cast<microseconds>(stop_splaytree - start_splaytree);
            inputFile.close();

            cout << "Splay Tree insertion time: " << duration_splaytree.count() << " microseconds" << endl;

            searchFile.open(searchFileName);
            auto start_search_splaytree = high_resolution_clock::now();
            searchSplayTree(splayTree, searchFile);
            auto stop_search_splaytree = high_resolution_clock::now();
            auto duration_search_splaytree = duration_cast<microseconds>(stop_search_splaytree - start_search_splaytree);
            searchFile.close();

            cout << "Splay tree search time: " << duration_search_splaytree.count() << " microseconds" << endl;
            cout << endl;

            inputFile.open(fileName);
            auto start_rbtree = high_resolution_clock::now();
            insertRedBlackTree(rbTree, inputFile);
            auto stop_rbtree = high_resolution_clock::now();
            auto duration_rbtree = duration_cast<microseconds>(stop_rbtree - start_rbtree);
            inputFile.close();

            cout << "Red-Black Tree insertion time: " << duration_rbtree.count() << " microseconds" << endl;

            searchFile.open(searchFileName);
            auto start_search_rbtree = high_resolution_clock::now();
            searchRedBlackTree(rbTree, searchFile);
            auto stop_search_rbtree = high_resolution_clock::now();
            auto duration_search_rbtree = duration_cast<microseconds>(stop_search_rbtree - start_search_rbtree);
            searchFile.close();

            cout << "Red-Black tree search time: " << duration_search_rbtree.count() << " microseconds" << endl;

            cout << endl;
        }
    }

    return 0;
}
