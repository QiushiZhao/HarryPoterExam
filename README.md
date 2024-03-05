# HarryPoterExam
Harry Poter's Exam

In Professor McGonagall's class of Transfiguration, Harry Potter is learning how to transform one object into another by some spells. He has learnt that, to turn a cat into a mouse one can say `docamo`! To reverse the effect, simply say `decamo`! Formally speaking, the transfiguration spell to transform between object A and object B is said to be `S` if there are two spells, `doS` and `deS`, to turn A into B and vice versa, respectively.

In some cases, short-cut spells are defined to make transfiguration easier. For example, suppose that the spell to transform a cat to a mouse is `docamo`, and that to transform a mouse into a fatmouse is `dofamo`, then to turn a cat into a fatmouse one may say `docamodofamo`! Or if a shot-cut spell is defined to be `cafam`, one may get the same effect by saying `docafam`!

Time is passing by quickly and the Final Exam is coming. By the end of the transfiguration exam, students will be requested to show Professor McGonagall several objects transformed from the initial objects they bring to the classroom. Each of them is allowed to bring 1 object only.

Now Harry is coming to you for help: he needs a program to select the object he must take to the exam, so that the maximum length of any spell he has to say will be minimized. For example, if cat, mouse, and fatmouse are the only three objects involved in the exam, then mouse is the one that Harry should take, since it will take a 6-letter spell to turn a mouse into either a cat or a fatmouse. Cat is not a good choice since it will take at least a 7-letter spell to turn it into a fatmouse. And for the same reason Harry must not take a fatmouse.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N (≤100) and M, which are the total number of objects involved in the exam and the number of spells to be tested, respectively. For the sake of simplicity, the objects are numbered from 1 to N. Then M lines follow, each contains 3 integers, separated by a space: the numbers of two objects, and the length of the spell to transform between them.

Output Specification:
For each test case, print in one line the number of the object which Harry must take to the exam, and the maximum length of the spell he may have to say. The numbers must be separated by a space.

If it is impossible to complete all the transfigurations by taking one object only, simply output 0. If the solution is not unique, output the one with the smallest number.

Sample Input:
```
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
```
Sample Output:
```
4 70
```
