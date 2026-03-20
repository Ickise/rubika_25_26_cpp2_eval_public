# Evaluation

1. [Information](#information)
2. [Theorical questions](#theorical-questions)
3. [Debugging](#debugging)
4. [Islands](#islands)
4. [Development]

## Information

### Rating

- In the case of no coding exercises, the rating will depend of the answer you will make
- In the case of coding exercises, the rating will be composed of:
 * The execution of the program answers the expectations
 * Have edge cases been into account?
 * ...
- The entire code you will submit, will be kept in the exact same case **unless it is explicitly told**. In that case, some files might be replaced to run some tests. The global rating of the exercise will depend of the number of success tests, so **take time to test your code and think about what can go wrong**.
- The way you have coded, the code quality, lisibility, leaks... are also part of the global rating of the exercises.

**Keep in mind that a code that does not compile cannot be run. In that case lots of points will be lost**

### Submit quality

- The way you will deliver your submission is also evaluated (even if it is not the main part of the rating).
- You must submit a `FIRSTNAME_LASTNAME.zip` file in the [drive](https://drive.google.com/drive/folders/1tjb82ApAw2-n3d2EqMAIx7b7sjomUI81?usp=drive_link)
- Late submission will be penalized
- Every unecessary files must be removed from your archive
 * `git` files
 * temporary files such compilation files for instance
 * IDE files 
- Your final project's weight must be close to the initial project (because you will only submit text files).

## Exercises

### Theorical questions
*Folder* : **Questions**\
*Estimated maximal time* : 20 minutes

You will find in this folder a markdown file which contains several questions. You must answer those questions directly in the file.

- Don't bother you with markdown notation, text format is sufficient
- Don't write tons of lines for each questions. Short and precise answer will be appreciate.

### Debugging
*Folder* : **DirtySpaceInvaders**\
*Estimated maximal time* : 90 minutes

In this folder, you will find a broken and bugy solution that you have to fix.

Just in case you have no idea what a `Space Invader` is, here are some references :
- [Video](https://www.youtube.com/watch?v=8Rbi8cfDvVY).
- [Online video game](https://freeinvaders.org/)

Here some infornation about the 

In the `CleanSpaceInvaders` folder, you will find two executables which show you what the program looks like once it has been fixed. One of them uses a seed so you can reproduce the same behavior on our side using
```c++
	// Change the seed by the one you want to try
	rGen.seed(1);
```

You are free to fix the program in the way you want (the clearer the better) but you have to keep a track of what you are doing, what is wrong, why... in the `recap.txt` file.

### Islands
*Folder* : **Islands**\
*Estimated maximal time* : 20 minutes

To analyze satellite images, a geospatial company studies maps of remote ocean regions.
Each map is represented as a grid where land and water are identified.
In this exercice, you have to determine how many separate islands are present on a given map.
The map is represented as a 2D grid of characters :
	- '1' represents land
	- '0' represents water

An island is defined as a group of connected land cells.
Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
The grid is surrounded by water.

**The `main` function is the only one that must not contain any code because it will be replaced. All code in that function will be lost. However, you can use it as a sandbox, you are free to use the way you want while developing.**

### Development
*Folder* : **DirtySpaceInvaders**\

This exercice is a "going further" exercice that I advise you to look at the end. It must be done after the [Debugging exercice](#debugging) has been completed.

Now the initial program has been fixed, it is time to add new features. Here is a small list of ideas but you can be creative and develop any new features.
- Adding rock which block a laser shot (ally? enemy?)
- Collision between lasers
- Big alien which has more life points