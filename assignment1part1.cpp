#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int insertIntoSortedArray(int sortedarray[], int entries, int insertvalue);

int main()
{
  int mainarray[100];
  string filenamestr = "assignment_1_problem_1.txt";
  string linein;
  int entriesmain = 0;
  int insertnum;

  ifstream file;
  file.open(filenamestr);

  while(getline(file,linein))
  {
    insertnum = stoi(linein);
    cout<<entriesmain+1 <<". ";
    entriesmain = insertIntoSortedArray(mainarray,entriesmain,insertnum);
    for(int i = 0;i<entriesmain;i++)
    {
      cout << mainarray[i] << ", ";
    }
    cout << "\n";
  }

  file.close();
  return 0;
}

int insertIntoSortedArray(int sortedarray[], int entries, int insertvalue)
{
  int set = 0;
  int intermediary;
  int intermediary2;
  for(int i=0;i<=entries;i++)
  {
    if(set==1)
    {
      intermediary2 = sortedarray[i];
      sortedarray[i] = intermediary;
      intermediary = intermediary2;
    }
    else
    {
      if(sortedarray[i]>insertvalue)
      {
        set = 1;
        intermediary = sortedarray[i];
        sortedarray[i] = insertvalue;
      }
      else
      {
        if (set==0&&i==entries)
        {
          sortedarray[i] = insertvalue;
        }
      }
    }
  }
  return entries+1;
}
