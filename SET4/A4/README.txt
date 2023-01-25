How did you structure your Player?
    I made my player a class. I know that there were a fair amount of functions for it, so I thought that a class was the best structure.

How did you structure your Game?
    I made my game a structure, just to practice using both structures and classes. 
How did you make use of classes and functions? What went where?
    I kind of oriented a player to be like a node with a pointer to the players to the left and right of them.
    Because I made these Player* values, the player number, and the number of chips they had private, I had to make getters and setters for all these data members.
    I had the chip to center and chip to player functions defined in the player class because I thought that they would work well exclusively in that class, but I did have to 
    add in a center_chips ++ in the switch statement because the Game LRC object wasn't defined in the scope of the function documentation
    
    For the actual Game, I knew that all I needed was to make a linked list of players, each one containing their place in the list, and so I just made two functions within Game.
    I also thought that it was clever to make the linked list return a pointer to the first player, otherwise I don't know how I would have referenced the list.

    The only function I defined outside of my classes/structs was roll(), which was my random number generator. I initially considered 
    making this a class also, but then I realized how complicated it would have been to make the die interract with the data members and member functions of the player classes. 

    The meat of the program was the switch statement that called functions from the player, but by procedurally programming those functions earlier even this wasn't too hard.

EXTRA CREDIT:
1. I chose to run 100 instances, because I figured that the more simulations the better, and I wasn't sure how to exactly calculate the number of simulations to reach a stable average
2. It looks like the relationship is exponential, with an equation of approximately turns = 9.43e^.656x

# Players | # Turns
----------|--------
     2    | 8
     3    | 23
     4    | 40
     5    | 54
    10    | 123
    20    | 260