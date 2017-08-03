#include<iostream>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;

class Terret{
private:
  int x1,x2,y1,y2;
  int r1, r2;
  double distanceAB;
public:
  Terret(int a = 0){
    x1=a,x2=a,y1=a,y2=a,r1=a,r2 = a;
  }
  ~Terret(){};
  void setTerretInfo1(int x, int y, int r);
  void setTerretInfo2(int x, int y, int r);
  void calDistance();
  int calCase();
};

void Terret::setTerretInfo1(int x, int y, int r){
  x1 = x;
  y1 = y;
  r1 = r;
}
void Terret::setTerretInfo2(int x, int y, int r){
  x2 = x;
  y2 = y;
  r2 = r;
}
void Terret::calDistance(){
  int x = x2 - x1;
  int y = y2 - y1;
  distanceAB = sqrt(pow(x,2)+pow(y,2));
}

int Terret::calCase(){
  //거리가 0일때 무한대이거나 가능한게 없거나
  if(distanceAB == 0){
    if(r1 == r2)  return -1;
    else return 0;
  }
  //거리가 0이 아니면 무조건 양수 그러므로 r1+r2 혹은 r1-r2의 절대값과 비교
  else if(distanceAB > (r1+r2)) return 0;
  else if(distanceAB == (r1 + r2) || distanceAB == abs(r1-r2))  return 1;
  else if(distanceAB < abs(r1-r2)) return 0;
  else return 2;
}

int main() {
	int repeat = 0;
	Terret A;
    /*
	ifstream input("input.txt");
	if (input.fail())
	{
	cout << "파일이 없습니다." << endl;
	return 0;
	}
	else {
		input >> repeat;
		for (; repeat > 0; repeat--) {
			int x1, x2, y1, y2, r1, r2;
			input >> x1;
            input >> y1;
            input >> r1;
            input >> x2;
            input >> y2;
            input >> r2;
			A.setTerretInfo1(x1,y1,r1);
            A.setTerretInfo2(x2,y2,r2);
            A.calDistance();
			cout << A.calCase()<<endl;
		}
	}*/

    cin >> repeat;
    for (; repeat > 0; repeat--) {
        int x1, x2, y1, y2, r1, r2;
        cin >> x1;
        cin >> y1;
        cin >> r1;
        cin >> x2;
        cin >> y2;
        cin >> r2;
        A.setTerretInfo1(x1,y1,r1);
        A.setTerretInfo2(x2,y2,r2);
        A.calDistance();
        cout << A.calCase()<<endl;
    }

	return 0;
}
