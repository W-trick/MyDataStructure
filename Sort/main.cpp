#include "mainwindow.h"
#include <QApplication>
#include "solution.h"
#include <vector>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Solution s;

    int b[8] = {8, 1, 14, 3, 21, 5, 7, 10};

    std::vector<int> vc(b, b + 8);

//    s.heapsort(vc, vc.size());

  //  s.mergeSort(vc, 0, vc.size() - 1);
    s.quickSort(vc, 0, vc.size() - 1);

//    s.TopK(vc, 0, vc.size() - 1, 5);
//    for(int i = 0; i < 5; ++i)
//    {
//        std::cout<<vc[i]<<std::endl;
//    }
    int index = s.BinarySerach(vc, 14);
    std::cout<<"index"<<index<<std::endl;

    for(std::vector<int>::const_iterator it = vc.cbegin(); it != vc.cend(); ++it)
    {
        std::cout<<*it<<std::endl;
    }



    MainWindow w;
    w.show();

    return a.exec();
}
