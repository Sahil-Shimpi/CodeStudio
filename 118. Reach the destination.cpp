// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380920?leftPanelTab=0

/*
	Time complexity: O(max(x, y))
	Space complexity: O(max(x, y))

	Where (x, y) is the coordinates of the destination point
*/

bool reachDestination(int sx, int sy, int dx, int dy )
{
    
    // Destination reached
	if (sx == dx && sy == dy) 
    {
		return true;
	}

	// Base case
	if (sx > dx || sy > dy) 
    {
		return false;
	}

	// Recursive call
	if (dx > dy) 
    {
		return reachDestination(sx, sy, dx - dy, dy);
	} 
    else 
    {
		return reachDestination(sx, sy, dx, dy - dx);
	}
}
