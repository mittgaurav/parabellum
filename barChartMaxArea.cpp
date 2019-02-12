#include <iostream>
#include <stack>
#include <algorithm>

int pos[] = {5, 3, 4, 0, 2, 2, 4};

// beautiful print bar chart
void print() {
  size_t n = sizeof(pos)/sizeof(int);
  
  // find max
  int max = 0;
  for(size_t i = 0; i < n; ++i)
    max = std::max(max, pos[i]);

  std::cout << "0 ";
  for(int i = 0; i <= max; ++i)
    std::cout << i << "_";
  std::cout << "\n";
  for(size_t i = 0; i < n; ++i) {
    int spaces = 2 * pos[i];
    std::cout << i + 1 << " [";
    while(--spaces >= 0)
      std::cout << "_";
    std::cout << "] " << pos[i] << "\n";
  }
}

// beautiful print a stack
void printS(std::stack<int> stack) {
  std::stack<int> temp = stack;
  size_t n = temp.size();
  std::cout << "\n";
  for(size_t i = 0; i < n; ++i) {
    int val = temp.top(); temp.pop();
    std::cout << "| " << val << " |\n";
    std::cout << "|___|\n";
  }
}

int maxArea(int* pos, size_t n){
  std::stack<int> positions;
  std::stack<int> heights;
  
  int max = 0;
  for(size_t i = 0; i < n; ++i) {
    int h = pos[i];

    if(positions.empty()) {
      // There is nothing on stack
      max = std::max(max, h * 1);
      positions.push(i);
      heights.push(h);
    }
    else {
      int lP = 0;
      if(h < heights.top()) {
        // The value we have is smaller than the adjacent one. Thus,
        // this value for this location can't be largest
        while(!heights.empty() && h < heights.top()) {
          lP  = positions.top();

          // can I construct a box with this h from an earlier location...
          max = std::max(max, h * (int(i) + 1 - lP));

          // can an earlier height, which are invariably larger than 
          // current h, create a box from its designated location till
          // previous location.
          max = std::max(max, heights.top() * (int(i) - lP));

          // We can remove previous highs as they are not going to
          // get larger now.
          heights.pop();
          positions.pop();
        }
        positions.push(lP);
        heights.push(h);
      }
      else {
        // The value is larger than adjacent one. Which means, I can 
        // have a max here or I can start a forward of this much height
        max = std::max(max, h * 1);
        heights.push(h);
        positions.push(i);
      }
    }
  }
  
  printS(heights);
  printS(positions);
  
  // So, we got a list of all the possible starting points that are valid 
  // till the end and their starting points.
  while(!heights.empty()) {
    int t = heights.top();
    int l = positions.top();
    max   = std::max(max, t * (int(n) - l));
    heights.pop();
    positions.pop();
  }

  return max;
}

int main() {
  print();
  std::cout << "max area: " << maxArea(pos, sizeof(pos)/sizeof(int));
}