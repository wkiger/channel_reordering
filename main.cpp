#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // initializing the 3-dimensional array
    int x[2][3][2] = { { { 0, 1 }, { 2, 3 }, { 4, 5 } },
                       { { 6, 7 }, { 8, 9 }, { 10, 11 } } };
//    this is a  2x2x3 array
//dim 1
//0 1
//2 3
//4 5
//
//dim 2
//6  7
//8  9
//10 11

//    Element at x[0][0][0] = 0
//    Element at x[0][0][1] = 1
//    Element at x[0][1][0] = 2
//    Element at x[0][1][1] = 3
//    Element at x[0][2][0] = 4
//    Element at x[0][2][1] = 5
//    Element at x[1][0][0] = 6
//    Element at x[1][0][1] = 7
//    Element at x[1][1][0] = 8
//    Element at x[1][1][1] = 9
//    Element at x[1][2][0] = 10
//    Element at x[1][2][1] = 11

    vector<int> flattenedList;
    vector<vector<int>> vectVector;
//    stack<int> flattenedStack;
    //we know we have a 2x3x2 3-d arrary... now reverse slices
    for (int i = 0; i < 2; ++i) //i should be column
    {
        for (int j = 0; j < 3; ++j) //j should be row
        {
            for (int k = 0; k < 2; ++k)
            {
//                cout << "eleme nt at i: " << i << ", j: " << j << ", k: " << k << " == " << x[i][j][k] <<endl;
//                cout << "k== " << k << endl;
                flattenedList.push_back(x[i][j][k]);
//                cout << "flattenedList size: " << flattenedList.size() << endl;

                if(flattenedList.size() == 6) //i will know 6 will be the size
                {
                    vectVector.push_back(flattenedList);
                    //clear the list for the next NxN array
                    flattenedList.clear();
                }
            }
        }
    }


    //stack to reverse the frames
    stack<vector<int>> my_stack;

    //print the vector
    cout << "printing the vector -- should be empty" << endl;
//    for (int i = 0; i< flattenedList.size(); ++i)
    for (int i : flattenedList)
    {
        cout << i << " ";
    }


    cout << "printing the vector vector" << endl;
    for (int i = 0; i < vectVector.size(); i++)
    {
        for (int j = 0; j < vectVector[i].size(); j++)
        {
//            cout << "i == " << i << " j == " << j << endl;
//            cout << "value == " << vectVector[i][j] << "\n ";

//            cout<<"times executes = " << last_value << endl;
//            last_value++;

//            cout << "vect vect [i] size: " << vectVector[i].size() << endl;
//            if(j == 5) //will know this 5 value for the arr size
            if(j == vectVector[i].size()-1)
            {
//                cout << "----------" << endl;
//                last_i = i;
                my_stack.push(vectVector[i]);
            }

            //my_stack.push(vectVector[i]);
        }
    }

//dim 1
//0 1
//2 3
//4 5
//
//dim 2
//6  7
//8  9
//10 11

    cout << "\n\n Wonder what this will do..." << endl;
    while(!my_stack.empty())
    {
        for(int i : my_stack.top())
//        for (int i = 0; i < my_stack.top().size(); i++)
        {
            cout << i << " ";
        }
        cout << "\n --------  \n";
        my_stack.pop(); //this is popping a vector
    }



    return 0;
}









//print vector of vectors...with iterator https://stackoverflow.com/questions/35342640/how-to-print-vector-of-vectors-using-vector-begin-to-vector-end
//    cout << "\nprinting the vector of vectors" << endl;
//    for (auto row = vectVector.begin(); row != vectVector.end(); ++row)
//        for (auto col = row->begin(); col != row->end(); ++col) {
//            cout << *col << " ";
//        };

//    for(vector< vector<int> >::iterator row = vectVector.begin(); row != vectVector.end(); ++row) {
//        for(vector<int>::iterator col = row->begin(); col != row->end(); ++col) {
//            cout << *col;
//        }
//    }




//    // output each element's value
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            for (int k = 0; k < 2; ++k) {
//                cout << "Element at x[" << i << "][" << j
//                     << "][" << k << "] = " << x[i][j][k]
//                     << endl;
//            }
//        }
//    }




//    // output each element's value --i, j only
//    for (int i = 0; i < 2; ++i) //i should be column
//    {
//        cout << "i == " << i << endl;
//        for (int j = 0; j < 3; ++j) //j should be row
//        {
////            cout << "Element at x[" << i << "][" << j
////                 << "][" << j << "] = " << x[i][j][0]
////                 << endl;
//            cout << "j == " << j << endl;
////            cout << x[i][j][0] << endl;
//            for (int k = 0; k < 2; ++k)
//            {
//                cout << "element at i: " << i << ", j: " << j << ", k: " << k << " == " << x[i][j][k] <<endl;
////                cout << "k== " << k << endl;
//            }
//        }
//    }
