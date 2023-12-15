//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void floodFillDFS(int row, int col, int initialColor, int newColor, vector<vector<int>>& image) {

        // Base case for recursion
        if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || image[row][col] != initialColor)
            return;

        // Update the current pixel color
        image[row][col] = newColor;
        
        // Recursive calls in 4 directions
        floodFillDFS(row - 1, col, initialColor, newColor, image); // Up
        floodFillDFS(row + 1, col, initialColor, newColor, image); // Down
        floodFillDFS(row, col - 1, initialColor, newColor, image); // Left
        floodFillDFS(row, col + 1, initialColor, newColor, image); // Right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        
        if (initialColor != newColor) {
            floodFillDFS(sr, sc, initialColor, newColor, image);
        }
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends