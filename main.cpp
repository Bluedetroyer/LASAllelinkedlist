
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.cpp"

using namespace std;





void sortTotal(linkedList* sp, int l, int h);
int partition(linkedList* sp, int start, int end);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{

    ifstream infile;
    int i=0;
    char cNum[10] ;
    char temp[50];
    linkedList airportArr = linkedList();			// Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];
    
    infile.open ("USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        infile.getline(temp, 256, '\n');
        int   c=0;
        while (infile.good())
        {
          
            airportArr.add(new Airport());
            infile.getline(airportArr.get(c)->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr.get(c)->latitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr.get(c)->longitude = atof(cNum);
            
          

            /*if (!(c % 1000))
                cout << airportArr.get(c)->code << " long: " << airportArr.get(c)->longitude << " lat: " << airportArr.get(c)->latitude <<  endl;

            
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        /*
         for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr.get(c)->code << " long: " << airportArr.get(c)->longitude << " lat: " << airportArr.get(c)->latitude <<  endl;
                cout << airportArr.get(c+1)->code << " long: " << airportArr.get(c+1)->longitude << " lat: " << airportArr.get(c+1)->latitude <<  endl;
                cout <<"Distance between " << airportArr.get(c)->code << " and " << airportArr.get(c+1)->code << " is "
                  << distanceEarth( airportArr.get(c)->longitude, airportArr.get(c)->latitude , airportArr.get(c+1)->longitude, airportArr.get(c+1)->latitude) << endl;
            }*/



    }
    else
    {
        cout << "Error opening file";
    }


  sortTotal(&airportArr, 0, airportArr.size() - 2);

  cout << airportArr.get(0)->code << endl;
 
  for (int i = 0; i < airportArr.size(); i++) {
    if (distanceEarth(30.1944, 97.6700, airportArr.get(i)->latitude, airportArr.get(i)->longitude) <= 100) {
      cout << airportArr.get(i)->code << " ";
    }
    else {
      break;
    }
  }
  
    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/

void sortTotal(linkedList* sp, int l, int h)
{
  
  if (l >= h) {
    return;
  }
  int p = partition(sp, l, h);
  
  
  sortTotal(sp, l, p - 1);
  sortTotal(sp, p + 1, h);

} 

int partition(linkedList* sp, int start, int end) {
  int pivot = end;
  int distancePivot = distanceEarth(30.1944, 97.6700, (*sp).get(pivot)->latitude, (*sp).get(pivot)->longitude);

  int i = start - 1;

  for (int j = start; j < end; j++) {
    Airport* current = (*sp).get(j);
    //cout << i << " " << j << endl;
    if (distanceEarth(30.1944, 97.6700, current->latitude, current->longitude) <= distancePivot) {
      i++;

      (*sp).exchg(i, j);
    }

    
  }
  (*sp).exchg(i+1, end);
  return i + 1;
}