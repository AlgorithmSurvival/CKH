#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(10);
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    const int border = 10000000000; // 높일수록 정확도 오름.
    const double abx = (bx - ax) / border;
    const double aby = (by - ay) / border;
    const double cdx = (dx - cx) / border;
    const double cdy = (dy - cy) / border;

    double curAbx = ax;
    double curAby = ay;
    double curCdx = cx;
    double curCdy = cy;

    int low = 0;
    int high = border - 1;
    double result;


    while (low <= high)
    {
        int midLeft = (high - low) / 3 + low;
        int midRIght = (high - low) / 3 * 2 + low;

        curAbx = ax + abx * midLeft;
        curAby = ay + aby * midLeft;
        curCdx = cx + cdx * midLeft;
        curCdy = cy + cdy * midLeft;

        double leftDist = sqrt(pow(curCdx - curAbx, 2) + pow(curCdy - curAby, 2));

        curAbx = ax + abx * midRIght;
        curAby = ay + aby * midRIght;
        curCdx = cx + cdx * midRIght;
        curCdy = cy + cdy * midRIght;

        double rightDist = sqrt(pow(curCdx - curAbx, 2) + pow(curCdy - curAby, 2));

        //거리가 작아야 해답
        if (rightDist <= leftDist)
        {
            result = rightDist;
            low = midLeft + 1;
        }
        else
        {
            result = leftDist;
            high = midRIght - 1;
        }

    }

    cout << result;
    return 0;
    
}

