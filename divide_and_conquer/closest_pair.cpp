#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

// Struct to represent a point
struct Point {
	int x;
	int y;
};

/**
 * Returns square of Euclidian distance between 2 points
 */
int dist(Point &a, Point &b) {
	return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

/**
 * Function helps to compare x-coordinates while sorting vector of Points
 */
bool compareX(const Point &a, const Point &b) {
  return a.x < b.x;
}

/**
 * Function helps to compare x-coordinates while sorting vector of Points
 */
bool compareY(const Point &a, const Point &b) {
  return a.y < b.y;
}

/**
 * Finds the closes split pair i.e. a pair of points in which one point is on different sides of the
 * partitioning line.
 * @points_x vector of points sorted by x-coordinate
 * @points_y vector of points sorted by y-cordinate
 * @mid x-coordinate of the partitioning line
 * @min_dist minimum distance calculated so far excluding the split pair distances
 */
vector<Point> closestSplitPair(vector<Point> points_x, vector<Point> points_y, int mid, int min_dist) {
	vector<Point> split_pts, strip_y;
	for(int i=0; i<points_y.size(); i++) {
		if(abs(points_y[i].x-mid) < min_dist)
			strip_y.push_back(points_y[i]);
	}
	for(int i=0; i<strip_y.size(); i++) {
		for(int j=i+1; j<strip_y.size() && (strip_y[j].y-strip_y[i].y) < min_dist; j++) {
			int temp_dist = dist(strip_y[i], strip_y[j]);
			if(temp_dist < min_dist) {
				min_dist = temp_dist;
				if(split_pts.size() == 2)
					split_pts[0] = strip_y[i], split_pts[1] = strip_y[j];
				else {
					split_pts.push_back(strip_y[i]);
					split_pts.push_back(strip_y[j]);
				}
			}
		}
	}
	return split_pts;
}

/**
 * Recursive helper function which finds the closest pair by divide and conquer approach
 * @points_x vector of points sorted by x-coordinate
 * @points_y vector of points sorted by y-cordinate
 * @start starting index to traverse points_x vector
 * @end specifies where to end the traversal of points_x vector
 */
vector<Point> closestPairHelper(vector<Point> points_x, vector<Point> points_y, int start, int end) {
	// Base case: solved by naive or brute force approach
	if(end-start <= 3) {
		int min = INT_MAX;
		int pts_ind[] = {0, 0};
		for(int i=start; i<end; i++) {
			for(int j=start; j<end; j++) {
				if(i != j) {
					int temp_dist = dist(points_x[i], points_x[j]);
					if(temp_dist < min) {
						min = temp_dist;
						pts_ind[0] = i, pts_ind[1] = j;
					}
				}
			}
		}
		vector<Point> pts;
		pts.reserve(2);
		pts.push_back(points_x[pts_ind[0]]);
		pts.push_back(points_x[pts_ind[1]]);
		return pts;
	}
	else {
		// Divide
		int mid = (start+end)/2;
		vector<Point> l_pts = closestPairHelper(points_x, points_y, start, mid);
		vector<Point> r_pts = closestPairHelper(points_x, points_y, mid, end);

		// Conquer
		int min_dist = min(dist(l_pts[0], l_pts[1]), dist(r_pts[0], r_pts[1]));
		vector<Point> split_pts = closestSplitPair(points_x, points_y, mid, min_dist);
		if(split_pts.empty()) {
			if(dist(l_pts[0], l_pts[1]) > dist(r_pts[0], r_pts[1]))
				return r_pts;
			else
				return l_pts;
		}
		else
			return split_pts;
	}
}

void closestPair(vector<Point> &points) {
	// Sort points vector by x-coordinates a store in points_x
	vector<Point> points_x(points);
	sort(points_x.begin(), points_x.end(), compareX);

	// Sort points vector by y-coordinates a store in points_y
	vector<Point> points_y(points);
	sort(points_y.begin(), points_y.end(), compareY);

	// Calls the recursive helper function
	vector<Point> closest_pair = closestPairHelper(points_x, points_y, 0, points_x.size());

	// Prints the closest pair and distance
	cout << "Closest Pair: (" << closest_pair[0].x << ", " << closest_pair[0].y << "), (" <<
	closest_pair[1].x << ", " << closest_pair[1].y << ")" << endl;
	cout << "Distance: " << sqrt(dist(closest_pair[0], closest_pair[1])) << endl;
}

int main() {
	// vector<Point> points = {{1, 2}, {3, 4}, {7, 3}, {0, 0}, {-3, 5}};
	vector<Point> points = {{0, 0}, {1, 0}, {2, 3}, {12, 30}, {6,10}, {-1, 4},
	{25, 25}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	closestPair(points);
	return 0;
}