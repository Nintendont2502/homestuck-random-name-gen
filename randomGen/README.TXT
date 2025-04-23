Author: @nintendont2502 on tumblr, https://github.com/Nintendont2502. Direct all suggestions/complaints/bugs that way.
Created: 22/04/2025
Last updated: 23/04/2025

HOW TO USE:

The program's exe can be found at: homestuck-random-name-gen\randomGen\randomGen.exe. Run that.

When the program is started, the following menu will display:

Enter choice:
1. Last names: OFF
2. Classpect: OFF
3. Bloodtype: OFF
4. Moon alignment: OFF
5. Generate names with selected options.
6. Quit.

To toggle an option, enter it's respective number (e.g. to toggle last names on, enter 1). This menu will loop until you either select 5 (which generates names), or 6 (which ends the program). Once 5 is entered, the program will prompt you to enter the number of names you want to generate - it will then generate that number of names (along with any toggled options - e.g. classpect, bloodtype, etc), before taking you back to the menu to change your choices. This menu will repeat until 6 is entered, and the program ends. 

When the program asks for a number, don't enter a letter. Or do. I'm not the boss of you. Just know that if it breaks everything it's your fault. 

FAQ:

Q: Why?
A: Great question! I ask myself the same thing every day.

Q: Why this program specifically?
A: I'll be honest, this basically just exists for me to practice my CPP design skills, since they are.... lacking. Getting useable names out of this is... unlikely, given the way they're created, but hey. Sometimes there's some passable ones. If you're writing a fanfic and just need some one off background names with no meaning and no effort put into them whatsoever, then odds are you'll be able to find some here. Or hell, use them for your OC that you don't care enough about to research names with actual meaning. Or one off trolls with bloodtypes and classpects to practice design creation. Or just see how long it takes for the program to create a canon name. Or how long it takes to create a real word (the only one I've gotten so far is "iTunes"). Or see how long it takes to break it. The possibilities are truly endless. 

Q: How exactly are names generated?
A: First, a random CV (consonant vowel) pattern is selected from the 22 canonical CV patterns used within Homestuck (and it's extended universe - Hiveswap, Friendsim, Beyond Canon, etc). These 22 patterns are the same patterns that every single canon troll name uses (if you're curious to see the breakdown, it can be found within "name patterns.ods" - note that some names within that spreadsheet are from a fansession I'm in, and aren't canon names. Any unique patterns from those names are not listed within the CV list the program uses, but they *are* included in the alternate CV list included in this repo.). The program then takes the chosen pattern, and randomly selects a consonant for each C, or a vowel for each V, creating something that almost looks like a name!

Q: Can I add my own patterns?
A: You can! The program is designed to be able to take any CV pattern list of any length, as long as it follows the same format:

- Every entry on the list must be separated by a new line.
- The first line of the list must be the number of patterns in the list 
- Each subsequent line should only have one 6 letter pattern, with no punctuation, spaces, or other text
- Each pattern should only contain C or V, and only in uppercase

There are two ways to import your own list into the program:

1. Find the "allUniquePatterns_canonOnly.txt" file within the randomGen folder, and replace it with your own list (making sure you follow the established formatting, and don't rename the file). This is the default file the program reads from, so any edits to it should automatically be reflected within the program itself.

2. Open "genlib.cpp", and scroll down to the 'getSize()' and 'fillList()' functions. Each contains a line of code reading "ifstream infile("allUniquePatterns_canonOnly.txt");" - replacing "allUniquePatterns_canonOnly" with your own file's name, and moving that file into the same folder as the original file, will cause the program to load that file instead. If you use this method, ensure that the infile name is changed in both getSize AND fillList, or it won't work.

Q: I found a bug/I broke something/something isn't working. What do I do?
A: Let me know what happened and how you caused it over at @nintendont2502 on tumblr, and I'll fix it. Maybe. Or I'll forget. Or I won't be able to figure it out. Or it'll just be because you did something stupid and at that point it's survival of the fittest.

Q: Can I use these names for anything? Do you require credit?
A: Do whatever you want with them forever! I don't give a shit! Credit or a link to the repo would be nice but isn't necessary - although if you do use them for anything, I'd be curious to see what it is, so let me know if you feel like it.

Q: Your program called me a faggot.
A: Not a question!

Q: Your program called me a faggot. What do I do about this?
A: Screenshot and send it to me immediately. Do you know how long I've been waiting for it to do that. 

Q: Your code sucks.
A: What are you, my tutor?