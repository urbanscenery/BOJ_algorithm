#include<iostream>
#include<algorithm>

using namespace std;

class addFile{
private:
    int file[502][502];
    int page;

public:
    void setPage(int a){page = a;};
    void init(int j, int cost);
    int calCost(int a, int b);
};


int addFile::calCost(int a, int b){
    if(a==b) return file[a][b];
    else{
        int cost = 99999999;
        for(int i = a ; i<b ; i++){
            int temp = calCost(a,i) + calCost(i+1,b);
            printf("----file : %d\n", file[a][b]);
            if(temp<cost) cost = temp;
        }
        file[a][b] = cost;
        return file[a][b] + cost;
    }
}

void addFile::init(int j, int cost){
    file[j][j] = cost;
}

int main(){
    int testCase;
    addFile A;
    scanf("%d", &testCase);
    for(int i = 0 ; i<testCase ; i++){
        int page;
        scanf("%d", &page);
        A.setPage(page);
        for(int j = 1 ; j<=page ; j++){
            int cost;
            scanf("%d", &cost);
            A.init(j, cost);
        }
        printf("%d\n", A.calCost(1,page));
    }
    return 0;
}
