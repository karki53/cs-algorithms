/*

Author-Krishan singh karki
Algorithm name-Sweep Line Algorithm for nearest points.
This algorithm is implementation of famous Sweep line algorithm for 
for Shortes distance between two points from N number points.
Time Complexity- nlogn

*/

/*
HACKTOBERFEST
*/

#include<bits/stdc++.h>
using namespace std;
double closestPointsDistance(vector< pair < int , int > > points, int n){
	
	set< pair < int , int > > Sweep_Box;
	//sorting the points on the base of x axies
	sort(points.begin(),points.end());
	//Initializing the Shortest distance in "Ans" by Large value
	double Ans=100000,firstt=0;
	//Initializing the Sweep box with the first point
	Sweep_Box.insert(points[0]);

	for(int i=1;i<n;i++){
		//removing those points which are at distace greater than "Ans" distance;
		while(i>firstt && points[i].second-points[firstt].second > Ans){
			Sweep_Box.erase(points[firstt]);
			firstt++;
		}
		//Checking all points inside Sweep box for shortest path
		for(auto j=Sweep_Box.begin(); j!=Sweep_Box.end(); j++){
			//Using shortest distance Formula distance=SqareRoot of((x2-x1)^2+(y2-y2)^2)
			Ans = min( Ans ,sqrt( pow( points[i].first- j-> first, 2 ) +
			 pow(points[i].second - j->second, 2 ) ) );
			
		}
	Sweep_Box.insert(points[i]);
	}
	return Ans;
}
int main(){

	int n;
	cout<<"Enter the number of points in a 2d plane :";
	cin>>n;
	cout<<endl;

	vector< pair < int ,int > > points;
	cout<<"Enter the coordinates of points x and y for all points"<<endl;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}

	cout<<closestPointsDistance(points,n);
}


