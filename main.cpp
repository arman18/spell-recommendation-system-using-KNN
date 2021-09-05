#include <iostream>
#include <math.h>
#include <QStringList>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;

int weight = 20;
double strDist(std::string str1,std::string str2){
    int len1=str1.length(),len2 = str2.length();
    if(len1>len2){
        swap(str1,str2);
        std::swap(len1,len2);
    }

    double sum = 0,distance;
    double totalWeight = 0;
    int p1=0;
    for(int i=0;i<len2;i++){
        if(p1<len1){ // valid index;
            int pos1 = int(str1[p1]-96);
            int pos2 = int(str2[i]-96);
            distance = pow(pos1-pos2,2);
//            if(temp==0 || len1==len2){
            if(distance==0){
                totalWeight+=weight/(i+1.0);
                //sum+=temp;
                p1++;
                continue;
            }
//            else {
//                sum+=pow(int(str2[i]-96),2); // from 0
//                continue;
//            }
        }
//        else{
//            sum+=pow(int(str2[i]),2); // from 0
//            continue;
//        }
    }
    //if(count) return sqrt(sum)/count;
    //return sqrt(sum)/0.001;
    return totalWeight;
}
bool compare_function( QPair<QString,double> x, QPair<QString,double> y) {
    if(x.second==y.second) return  x.first.length()<y.first.length();
    return x.second > y.second;
}

QList < QPair<QString,double> > Knn(QString input,QString inFile){
    QList < QPair<QString,double> > list;
    QFile file(inFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return list;
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString word = in.readLine();
      list.append(QPair<QString,double>(word, strDist(word.toStdString(),input.toStdString())));

    }
    qSort(list.begin(),list.end(),compare_function);
    return list;
}
int main(int /*argc*/, char *argv[])
{
    QString input = "coment";
    QString file = "C:/Users/mts/Documents/Qt/console/dict.txt";
    int recom = 3;
    string inp;
    while(true){
        cin>>inp;
        input = QString::fromStdString(inp);
        QList < QPair<QString,double> > list = Knn(input,file);
        cout<<"\n    recom: ";
        for(int i=0;i<recom;i++){
            if(i==list.length()) break;
            if(i) cout<<", ";
//            cout<<list[i].first.toStdString()<<list[i].second;
            cout<<list[i].first.toStdString();
        }
        cout<<endl;
    }
    return 0;
}
