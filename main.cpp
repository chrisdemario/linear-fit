#include <iostream>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getLinearFit(std::vector<double> &xData, std::vector<double> &yData, double &slope, double &intercept)
{
  double xSum = 0, ySum = 0;
  double xxSum = 0, xySum = 0;

  for(long i = 0; i < yData.size(); i++)
  {
    xSum += xData[i];
    ySum += yData[i];
    xxSum += xData[i] * xData[i];
    xySum += xData[i] * yData[i];
  }

  slope = (yData.size() * xySum - xSum * ySum) / (yData.size() * xxSum - xSum * xSum);
  intercept = (ySum - slope * xSum) / yData.size();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)                      
{

  try{
    double slope=0, intercept=0;
    std::vector<double> xData{8,2,11,6,5,4,12,9,6,1};
    std::vector<double> yData{3,10,3,6,8,12,1,4,9,14};

    for(int x=0; x < xData.size(); x++) {
      std::cout << "Input datapoint: " << x+1 << " --> [" << xData[x] << "," << yData[x] << "]\n";
    }

    getLinearFit(xData, yData, slope, intercept);
    std::cout << "\ngetLinearFit() slope(" << slope <<") intercept(" << intercept << ")\n\n";

  } catch( const exception &e){
    cout << "Main Exception:" << endl;
    cout << e.what() << endl;
  }

  return 0;
}

