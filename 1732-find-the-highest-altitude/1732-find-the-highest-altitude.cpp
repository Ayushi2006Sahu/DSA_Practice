class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int alt =0;
      int mx =0;
      for(int g:gain){
        alt+=g;
        mx = max(mx,alt);
      }
      return mx;
    }
};