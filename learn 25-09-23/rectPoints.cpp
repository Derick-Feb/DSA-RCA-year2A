#include <iostream>
#include <vector>

using namespace std;

struct Point{ int x; int y; };

void printingPoints(vector<Point> pts) {
  for(Point p: pts) {
    cout << "(" << p.x << ", " << p.y << ") ";
  }
};

vector<vector<Point>> verticalPoints(vector<Point> pts) {
  vector<vector<Point>> vertPts;

  for(Point pt1: pts) {
    for(Point pt2: pts){
      if(pt1.x == pt2.x) {
        if(pt1.y == pt2.y) continue;
        if(pt1.y > pt2.y) continue;
        vertPts.push_back({pt1, pt2});
      };
    }
  }

  return vertPts;
}

void printingVertPoints(vector<vector<Point>> vPts) {
  for(vector<Point> vPt: vPts) {
    cout << "( ";
    printingPoints(vPt);
    cout << ")" << endl;
  }
}

int RectCount(vector<vector<Point>> vPts) {
  int count = 0;
  
  for(auto vPt1: vPts) {
    for(auto vPt2: vPts) {
      if(vPt1[0].x < vPt2[0].x && vPt1[1].x < vPt2[1].x) {
        if(vPt1[0].y == vPt2[0].y && vPt1[1].y == vPt2[1].y) {
          count++;
        }
      }
    }
  }

  return count;
}

int main() {
  vector<Point> pointsGiven = {
    {1,1}, {1,2}, {1,3}, {1,4},
    {2,1}, {2,2}, {2,3}, {2,4},
    {3,1}, {3,2}, {3,3}, {3,4}
  };

  vector<vector<Point>> verticalPointsPairs = verticalPoints(pointsGiven);
  printingVertPoints(verticalPointsPairs);

  //array of vector<vector<vector<vector<Point>>>> rectPoints { { { x, y }, { x, y } }, { { x, y }, { x, y } } }

  int numberOfRects = RectCount(verticalPointsPairs);
  cout << endl << endl << "Number of rectangles: " << numberOfRects;

  return 0;
}