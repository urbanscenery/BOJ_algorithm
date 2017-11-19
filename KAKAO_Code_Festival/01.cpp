#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int pic[101][101][2];

void initPic(int m, int n, vector< vector<int> > picture){
    for(int i = 0 ; i < 101 ; i++){
        for(int j = 0 ; j < 101 ; j++){
            pic[i][j][0] = 0;
            pic[i][j][1] = -1;
        }
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            pic[i][j][0] = picture[i][j];
            pic[i][j][1] = 1;
        }
    }
}


int calPic(int i , int j){
    int size = 0;
    if(pic[i][j][1] <= 0) return 0;
    else if(pic[i][j][0] == 0 ){
        pic[i][j][1] = 0;
        return 0;
    }
    else if(j <= 0){
        pic[i][j][1] = 0;
        if((pic[i+1][j][0] == pic[i][j][0]) && (pic[i+1][j][1] > 0)){
            size += calPic(i+1, j);
        }
        if((pic[i][j+1][0] == pic[i][j][0]) && (pic[i][j+1][1] > 0)){
            size += calPic(i,j+1);
        }
        return size+1;
    }
    else{
        pic[i][j][1] = 0;
        if((pic[i][j-1][0] == pic[i][j][0]) && (pic[i][j-1][1] > 0)){
            size += calPic(i, j-1);
        }
        if((pic[i+1][j][0] == pic[i][j][0]) && (pic[i+1][j][1] > 0)){
            size += calPic(i+1, j);
        }
        if((pic[i][j+1][0] == pic[i][j][0]) && (pic[i][j+1][1] > 0)){
            size += calPic(i,j+1);
        }
        return size+1;
    }


}




// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector< vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    initPic(m,n,picture);

    for(int i = 0 ; i <m ; i++ ){
        for(int j = 0 ; j<n ; j++){
            if(pic[i][j][1] > 0 && pic[i][j][0]>0){
                max_size_of_one_area = max(calPic(i,j), max_size_of_one_area);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){
    vector<int> a(2);
    vector< vector<int> > test = [[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]];
    a = solution(6, 4, test);
    printf("%d, %d", a[0], a[1]);
    return 0;
}
