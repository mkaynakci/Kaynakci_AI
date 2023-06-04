#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include "BSTree.h"
#include "AVLTree.h"
#include "LinkedList.h"

using namespace std;

void print_ds_menu();
void print_operation_menu();
bool perform_operation(char);


int main()
{
    string file_gt = "../gt.txt";
    string file_predict = "../predict.txt";
    bool end = false;
    char choice_ds, choice_op;
    
    print_ds_menu();
    cin >> choice_ds;

    if (choice_ds == '1') //Binary Search Tree Selection
    {
        //BinSTree* bst = new BinSTree();
        BSTree* bst_gt = new BSTree();
        BSTree* bst_predict = new BSTree();

        while (!end)
        {
            print_operation_menu();
            cin >> choice_op;
            switch(choice_op) {
                case '1': {
                    auto start = chrono::high_resolution_clock::now();
                    ifstream file(file_gt);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        bst_gt->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST Ground truth data structure was created from file in : " << duration.count() << " microseconds" << endl;
                    break;
                }
                case '2': {
                    auto start = chrono::high_resolution_clock::now();
                    ifstream file(file_predict);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        bst_predict->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST prediction data structure was created from file in : " << duration.count() << " microseconds" << endl;

                    break;
                }
                
                case '3': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to add: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();
                    bst_predict->insert(chrom, pos, altBase);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST Adding Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                 }


                case '4': {
                     string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to delete: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now(); 
                    bst_predict->remove(chrom, pos, altBase);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST Removing Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                }
                
                case '5': {
                    cout << "Listing prediction variants:" << endl;
                    auto start = chrono::high_resolution_clock::now();
                    bst_predict->printInOrder();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST Listing Prediction Variants took : " << duration.count() << " microseconds" << endl;
               
                    break;
                }


                case '6': {
                    
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to search: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();
                    BSTNode* found = bst_predict->search(chrom, pos, altBase);
                    if (found != nullptr) {
                        cout << "Variant found: " << found->getChrom() << " " << found->getPos() << " " << found->getAltBase() << endl;
                    } else {
                        cout << "Variant not found." << endl;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "BST Searching a Prediction Variants took : " << duration.count() << " microseconds" << endl;               
                    break;
                }

                case '7': {
                    auto start = chrono::high_resolution_clock::now();                    
                    std::vector<BSTNode*> gt_nodes, predict_nodes;
                    bst_gt->storeInOrder(gt_nodes);
                    bst_predict->storeInOrder(predict_nodes);

                    int true_positive_count = 0;
                    for (BSTNode* gt_node : gt_nodes) {
                        for (BSTNode* predict_node : predict_nodes) {
                            if (gt_node->getChrom() == predict_node->getChrom() && gt_node->getPos() == predict_node->getPos() && gt_node->getAltBase() == predict_node->getAltBase()) {
                                true_positive_count++;
                                break;
                            }
                        }
                    }
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                    cout << "True positive variant count is: " << true_positive_count << endl;
                    cout << "BST Calculating TP took : " << duration.count() << " microseconds" << endl;               
                    break;
                }


                case '0': {
                    delete bst_gt;
                    delete bst_predict;
                    end = true;
                    break;
                }
                default: {
                    cout << "Invalid operation" << endl;
                }
            }

        }
    }

    else if (choice_ds == '2') //AVL Tree Selection
    {
        AVLTree* avt_gt = new AVLTree();
        AVLTree* avt_predict = new AVLTree();

        while (!end)
        {
            print_operation_menu();
            cin >> choice_op;
            // Fill here according to the choice

            switch(choice_op) {
                case '1': {
                    auto start = chrono::high_resolution_clock::now();                    
                    ifstream file(file_gt);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        avt_gt->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL Ground truth data structure was created from file in : " << duration.count() << " microseconds" << endl;

                    break;
                }
                case '2': {
                    auto start = chrono::high_resolution_clock::now();                      
                    ifstream file(file_predict);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        avt_predict->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL prediction data structure was created from file in : " << duration.count() << " microseconds" << endl;

                    break;
                }

                case '3': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to add: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();                     
                    avt_predict->insert(chrom, pos, altBase);

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL Adding Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                }

                case '4': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to delete: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();                      
                    avt_predict->remove(chrom, pos, altBase);

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL Removing Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                }


                case '5': {
                    cout << "Listing prediction variants:" << endl;
                    auto start = chrono::high_resolution_clock::now();                      
                    avt_predict->printInOrder();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL Listing Prediction Variants took : " << duration.count() << " microseconds" << endl;
                                   
                    break;
                }

                case '6': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to search: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();                       
                    AVLNode* found = avt_predict->search(chrom, pos, altBase);
                    if (found != nullptr) {
                        cout << "Variant found: " << found->getChrom() << " " << found->getPos() << " " << found->getAltBase() << endl;
                    } else {
                        cout << "Variant not found." << endl;
                    }
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "AVL Searching a Prediction Variants took : " << duration.count() << " microseconds" << endl;               

                    break;
                }


                case '7': {
                    auto start = chrono::high_resolution_clock::now();                         
                    std::vector<AVLNode*> gt_nodes, predict_nodes;
                    avt_gt->storeInOrder(gt_nodes);
                    avt_predict->storeInOrder(predict_nodes);

                    int true_positive_count = 0;
                    for (AVLNode* gt_node : gt_nodes) {
                        for (AVLNode* predict_node : predict_nodes) {
                            if (gt_node->getChrom() == predict_node->getChrom() && gt_node->getPos() == predict_node->getPos() && gt_node->getAltBase() == predict_node->getAltBase()) {
                                true_positive_count++;
                                break;
                            }
                        }
                    }

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                    cout << "True positive variant count is: " << true_positive_count << endl;
                    cout << "AVL Calculating TP took : " << duration.count() << " microseconds" << endl; 
                    break;
                }

                case '0': {
                    end = true;
                    break;
                }
                default: {
                    cout << "Invalid operation" << endl;
                }

            }
        }
    }

    else if (choice_ds == '3') //Linked List Selection
    {
        //LinkedList* ll = new LinkedList();

        LinkedList* ll_gt = new LinkedList();
        LinkedList* ll_predict = new LinkedList();

        while (!end)
        {
            print_operation_menu();
            cin >> choice_op;
            // Fill here according to the choice

            switch(choice_op) {
            case '1': {
                    auto start = chrono::high_resolution_clock::now();                 
                    ifstream file(file_gt);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        ll_gt->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList Ground truth data structure was created from file in : " << duration.count() << " microseconds" << endl;

                    break;
                }
                case '2': {
                    auto start = chrono::high_resolution_clock::now(); 
                    ifstream file(file_predict);
                    string line;
                    // Skip the first line
                    getline(file, line);
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string chrom, altBase;
                        int pos;
                        ss >> chrom >> pos >> altBase;
                        ll_predict->insert(chrom, pos, altBase);
                    }
                    file.close();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList prediction data structure was created from file in : " << duration.count() << " microseconds" << endl;

                    break;
                }

                case '3': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to add: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();                     
                    ll_predict->insert(chrom, pos, altBase);

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList Adding Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                }

                case '4': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to delete: ";
                    cin >> chrom >> pos >> altBase;
                    auto start = chrono::high_resolution_clock::now();                      
                    ll_predict->remove(chrom, pos, altBase);

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList Removing Prediction Variant took : " << duration.count() << " microseconds" << endl;

                    break;
                }

                case '5': {
                    auto start = chrono::high_resolution_clock::now();                    
                    ll_predict->printList();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList Listing Prediction Variants took : " << duration.count() << " microseconds" << endl;
                                                       
                    break;
                }

                case '6': {
                    string chrom, altBase;
                    int pos;
                    cout << "Enter CHROM, POS, ALT BASE of the variant to search: ";
                    cin >> chrom >> pos >> altBase;

                    auto start = chrono::high_resolution_clock::now();

                    ListNode* found = ll_predict->search(chrom, pos, altBase);
                    if (found != nullptr) {
                        std::cout << "Variant found: " << found->getChrom() << " " << found->getPos() << " " << found->getAltBase() << std::endl;
                    } else {
                        std::cout << "Variant not found." << std::endl;
                    }

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "LinkedList Searching a Prediction Variants took : " << duration.count() << " microseconds" << endl;               

                    break;
                    }

                case '7': {
                    auto start = chrono::high_resolution_clock::now();                         
                    std::vector<ListNode*> gt_nodes, predict_nodes;
                    ll_gt->storeNodes(gt_nodes);
                    ll_predict->storeNodes(predict_nodes);

                    int true_positive_count = 0;
                    for (ListNode* gt_node : gt_nodes) {
                        for (ListNode* predict_node : predict_nodes) {
                            if (gt_node->getChrom() == predict_node->getChrom() && gt_node->getPos() == predict_node->getPos() && gt_node->getAltBase() == predict_node->getAltBase()) {
                                true_positive_count++;
                                break;
                            }
                        }
                    }

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                    cout << "True positive variant count is: " << true_positive_count << endl;
                    cout << "Linked List Calculating TP took : " << duration.count() << " microseconds" << endl; 

                    break;
                }


                case '0': {
                    end = true;
                    break;
                }
                default: {
                    cout << "Invalid operation" << endl;
                }

            }
        }
    }

    else
    {
        cout << "Error: You have entered an invalid choice" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void print_ds_menu()
{
    cout << "Choose a data structure" << endl;
    cout << "1: Binary Search Tree" << endl;
    cout << "2: AVL Tree"<< endl;
    cout << "3: Unsorted Singly Linked List"<< endl;
    cout << "Enter a choice {1,2,3}:";
}

void print_operation_menu()
{
    cout << "Choose an operation" << endl;
    cout << "1: Create ground truth data structure from file" << endl;
    cout << "2: Create prediction data structure from file"<< endl;
    cout << "3: Add a variant prediction"<< endl;
    cout << "4: Delete a variant prediction"<< endl;
    cout << "5: List predictions"<< endl;
    cout << "6: Search a prediction variant from predictions"<< endl;
    cout << "7: Calculate true positive variant count"<< endl;
    cout << "0: Exit" << endl;
    cout << "Enter a choice {1,2,3,4,5,6,7,0}:";
}


