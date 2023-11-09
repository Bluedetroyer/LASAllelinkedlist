
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





void simpleSortTotal(linkedList s, int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
  



    ifstream infile;
    int i=0;
    char cNum[10] ;
    linkedList airportArr = linkedList();			// Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];
    
    infile.open ("USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
          
            airportArr.add(new Airport());
            infile.getline(airportArr.get(c)->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr.get(c)->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr.get(c)->latitude = atof(cNum);
            
          

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

  linkedList sortArr = airportArr.subList(1, airportArr.size() - 1);
  cout << "Test" << endl;
  sortTotal(airportArr, airportArr.size());

  cout << airportArr.toString();
 


    
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

void sortTotal(linkedList s, int c)
{
  Airport* target = s.get(10642);

	for (int i=0; i < c; i++) {
    cout << "Test\n";
		for (int j=i; j < c; j++) {
  		if (distanceEarth(target->latitude, target->longitude, s.get(i)->latitude, s.get(i)->longitude) > distanceEarth(target->latitude, target->longitude, s.get(j)->latitude, s.get(j)->longitude))
  		{
        s.exchg(i, j);
  		}
    }
  }
} 

int partition(linkedList s, int low, int high) {
  
}