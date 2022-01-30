# LibGenerator
Library Generator script for competitive programmers

## Install requirements:
  
  first you need to install the requirements.txt file
  
  **you can use:**
  > pip install -r /path/to/requirements.txt
  
## How to use:

  > python /path/to/main.py [/path/to/library_folder]
  
  if you don't provide the path to library folder then the script will consider it as you current directory
  
  > C:\Users\x\path\to\library_folder> python /path/to/main.py
  
 #### note that your library structure must be organized like this:
  
```
├───Library
   ├───Geometry
   │       area_of_triangle_given_3_points.cpp
   │
   ├───Gragh
   │       BellmanFord.cpp
   │       Bridges.cpp
   │       detectCycles.cpp
   │       dijkstra.cpp
   │
   ├───Math
   │       EulerPhiSieve.cpp
   │       factorial_mod_p.cpp
   │       FastMul.cpp
   │
   ├───Misc
   │       detectOverflow.cpp
   │
   └───Strings
           z_function.cpp
```
