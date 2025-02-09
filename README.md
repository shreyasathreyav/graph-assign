# Graph Assignment

This projects diretory structure is as follows 

```
├── Graph.h          # Contains the Graph class and solutions for Question 1
├── README.md       
├── helper.h         # Contains all function code for Question 2
├── input.txt        # Test cases for Question 1
├── input1.txt       # Test cases for Question 2
├── questions.pdf    # PDF document with problem statements
├── solution         
└── solution.cpp     # Main driver code for the project
```
---

## Test Cases Overview

### 1. **Test Cases for Question 1**
- **File:** `input.txt`
- **Description:** This file contains a single test case for Question 1.

**Structure of Test Case 1:**
```
1                  # to run question 1
1                  # Number of test cases
5 5                # Number of vertices and edges
1 2 a              # Edge from vertex 1 to 2 labeled 'a'
2 3 b              # Edge from vertex 2 to 3 labeled 'b'
1 3 c              # Edge from vertex 1 to 3 labeled 'c'
3 4 d              # Edge from vertex 3 to 4 labeled 'd'
3 5 e              # Edge from vertex 3 to 5 labeled 'e'
1                  # Starting node
2                  # Target node
4 5                # Query nodes
```
- **Graph:**
  - 5 vertices and 5 edges.
---

### 2. **Test Cases for Question 2**
- **File:** `input1.txt`
- **Description:** This file contains multiple test cases for Question 2.

**Structure of Test Cases in input1.txt:**
```
2                 # to run question 2

3                  # Number of test cases

2                  # Number of graphs in 1st testcase

5 5                # Graph 1: Number of vertices and edges
1 2 a              # Edge from vertex 1 to 2 labeled 'a'
2 3 b              # Edge from vertex 2 to 3 labeled 'b'
1 3 c              # Edge from vertex 1 to 3 labeled 'c'
3 4 d              # Edge from vertex 3 to 4 labeled 'd'
3 5 e              # Edge from vertex 3 to 5 labeled 'e'
1                  # Initial node
2                  # Number of Final nodes
4 5                # Final nodes

4 4                # Graph 2: Number of vertices and edges
1 2 a              # Edge from vertex 1 to 2 labeled 'a'
2 3 b              # Edge from vertex 2 to 3 labeled 'b'
3 4 d              # Edge from vertex 3 to 4 labeled 'd'
1 4 f              # Edge from vertex 1 to 4 labeled 'f'
1                  # Initial node
1                  # Number of Final nodes
4                  # Final nodes

2                  # Number of Graphs cases in the second testcase

3 3                #  Graph 1: Number of vertices and edges
1 2 x              # Edge from vertex 1 to 2 labeled 'x'
2 3 y              # Edge from vertex 2 to 3 labeled 'y'
1 3 z              # Edge from vertex 1 to 3 labeled 'z'
1                  # Initial node
1                  # Number of Final nodes
3                  # Final node

3 3                # Graph 2: Number of vertices and edges
1 2 x              # Edge from vertex 1 to 2 labeled 'x'
2 3 y              # Edge from vertex 2 to 3 labeled 'y'
2 1 w              # Edge from vertex 2 to 1 labeled 'w'
1                  # Initial node
1                  # Number of Final nodes
3                  # Final node

2                  # Number of Graphs in the third testcase

3 2                # Graph 1: Number of vertices and edges
1 2 l1             # Edge from vertex 1 to 2 labeled 'l1'
2 3 l2             # Edge from vertex 2 to 3 labeled 'l2'
1                  # Initial node
1                  # Number of Final nodes
3                  # Final node

3 2                # Graph 2: Number of vertices and edges
1 2 l2             # Edge from vertex 1 to 2 labeled 'l2'
2 3 l1             # Edge from vertex 2 to 3 labeled 'l1'
1                  # Initial Node
1                  # Number of Final node
3                  # Final node

```

- **Explanation:**
  - The file `input1.txt` includes 4 individual test cases grouped into two sets.
  - Each test case defines a graph structure, starting nodes, target nodes, and specific queries.
  - The graphs vary in size and complexity to ensure robust testing of different algorithmic scenarios.

---

## How to Use the Test Cases
1. Comment/Uncomment 

    // freopen("input.txt", "r", stdin); // to run question 1
    freopen("input1.txt", "r", stdin); // to run question 2

2. Run `solution.cpp`, which serves as the main driver code 
3. Compile the code using the following command:
   ```
   g++ -g solution.cpp -o solution
   ```
4. Execute the compiled code with:
   ```
   ./solution
   ```


