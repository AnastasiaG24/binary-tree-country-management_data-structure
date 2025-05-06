**# Binary Tree management**

A C program that manages country information using a binary tree data structure.
It allows insertion, in-order display, height and depth calculations, and more.

## Features
- Insert country data (name, capital, area, etc.)
- Calculate tree depth
- Calculate node depth (based on number of cities)
- Calculate node depth (based on number of cities)
- Calculate node height (based on area)
- Display all tree leaves
- Free memory

##Screen Captures 

In order to check if the program works correctly, I introduced information about 3 countries
![image](https://github.com/user-attachments/assets/32f2ab5e-e46e-4005-b614-e3a8bbf7d8d3)

### Results based on menu option

1. The result of choosing the first option from the meniu - Calculate tree depth
![image](https://github.com/user-attachments/assets/8822c444-a769-4321-8b15-c78f1e3e1e90)

2. The result of choosing the second option of the menu - Search for a node by key (foundation year)
![Screenshot 2025-05-06 194447](https://github.com/user-attachments/assets/06119f02-e6d6-4829-981b-2bd368e3092b)

3. For the same contries entered above, we have the result of the third option of the menu - Calculate node depth (based on number of cities)
   
![Screenshot 2025-05-06 194750](https://github.com/user-attachments/assets/a3334f38-ffb2-41e9-a64b-1850357dceed)

5. The result of the fourth option of the menu - Calculate node height (based on area)
![image](https://github.com/user-attachments/assets/1754b614-e0ce-46f5-8426-f50b8d259917)

6. The result of the fifth option of the menu - Display all tree leaves. 
![image](https://github.com/user-attachments/assets/5b08b51b-9eef-42ac-b5a2-bc091ffe904f)

Explanation of the result:
The binary tree is built based on the area.
The first node inserted is Moldova, which becomes the root.
The second node is Romania. Its area is compared with Moldova’s (238397 > 33843), so it is inserted to the right of the root.
The third node is Germany. Its area is compared with Moldova’s (357022 > 33843), so it goes to the right of the root, where Romania is already placed.
Then, Germany’s area is compared with Romania’s (357022 > 238397), so it is inserted to the right of Romania.

The tree looks like this:
       Moldova
            \
            Romania
                  \
                  Germania

## Language
- C
