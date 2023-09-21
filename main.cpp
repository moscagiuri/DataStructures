#include "exercises.h"


using namespace std;


int main() {

    // Exam 2 2022-02-14
    cout << "Exam 2 2022-02-14: " << endl;
    AddOnlyGraph<int> graph = buildGraph_Exam_2_2022_02_14();
    list<string> result = raggiungibili_Exam_2_2022_02_14(graph, "A", 3);
    // Print result
    cout << "Result: ";
    for (auto & it : result) {
        cout << it << " ";
    }



    // Exam X 202X-XX-XX



    return 0;
}