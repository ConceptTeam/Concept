# Alexandre Bismuth Reporting File

Part of the Backend Team. Working on the Data Organisation & Storage, the Search bar, the Kernel implementation, and the text editor. Details of each of these features can be found in the Week 1 report. Please note that most of my work is not in this repository, but in the Backend repository. I would also like to add that my handed in individual report is globally much clearer and more consistent, even if it doesn't capture the exact progress and thought process I had every week regarding the project.

## Week 1

Discussed the project as a group and started doing personal research to evaluate the feasability and the structure of all the features I would be working on.

1. Data Organisaion - Started doing research about handling of Data in C++ to avoid using pure SQL. Therefore, I think we will have to use SQLiteCpp, a library which allows us to use SQL within a C++ file.
2. Search bar - Started doing reasearch about implementation of search bars in C++. I will divide the work in different steps : Data Indexing, Search Algorithm Implementation, Integration within the UI, Testing.
3. Kernel Implementation - Brainstormed and researched with Octave the feasability and the potential structure of a kernel which would run code inside our app similarly to a Jupyter Notebook. For now, we are still unsure how we could do this without comprimising the UX as opening a local host is inconvenient.
4. Text Editor - Plan to implement a feature which allows the user to have a text box formatted and highlighted as would be a code in VSCode: Command recognition, Box Creation, Syntax highlighting & code formatting databasing, integration and testing within UI.

## Week 2

Naturally, I am starting off the project by designing the first essential feature : the database Manager. With Hung, I have installed (and spent consequent time understanding) the SQLite_orm library, a library which allows us to manage our content files using SQL within a C++ file. To this purpose, I have written functions in a Backend cpp file which allow me to initialize a database of files, create new files, edit them, and delete them. Now, my next step is to organise all of these function in various files and classes for documents and integreated features.

## Week 3

This week, I continued the database implementation. To that end, I have organized every storage in one database file, with many different tables. Given our Frontend feature, I have written a BaseModel class which is a parent class which defines the overall structure of each storage class. For the subclasses (which inherit BaseModel), I have thus designed 5 of them. Note - which stores all of the text files, Folder - which organises the notes, Timer - which sets and stores timers, Focus Time - which stores the time spent working by the user, and Commands - which stores all of the commands that will be usable as shortcuts or to create graphs/images/code boxes...

For next week, my objective is to finalize this database implementation (with the Backend Team), and potentially start working the search bar, as planned in Week 1.

## Week 4

After restrucring the database with Hung to use structs instead of classes, the database should be done. I have constructed 20 tests of our database.hpp file which all build & pass. Then, I investigated the search bar. Thanks to the 'like' function of SQLite_orm which kind of acts as a search bar, all I needed to do what to implement 2 20 lines functions and the trick was done.

For next week, we will make sure that everyone on the front-end can properly integrate and use the database and I will try to work on the text editor, to add a feature where you can have a block which formats text as code.

## Week 5 (Post Vacations)

My main focus was to implement databases functions, such as the search engine feature within the files, as well as the saving/retrieving feature within the database.

With his update, Hung rearranged the folders, changed library, and redesigned the system, moving my code around (Even though he is now the author of the code, I greatly participated in it). Now that the Database system is implemented, I will be working on finding+editing a syntax highlighter for Python code as well as an interpreter, to eventually create a "edit and run Pyhon code" feature in our app. Even though the code will be in C++, our feature will only work on Python and not C++ because it is an interpretable language, compared to C++ which requires a compiler.

## Week 6

After spending some considertable time understanding the new structure as well as the way to interact with QML since I had been on the backend since the beginning, I started the actual implementation with the front-end of the Tool bar. As I was mentionning before I created a Word count feature which I made visible on the Menu, and defined the SearchReplace Class and Dialogs, in order to allow for local search and replace, within the text editor.

## Week 7

After some bug fixing, the Search function and the Replace function are now done. I had a lot of troubles with C++ signals (I was stuck on this with both Professors during the whole TD) but managed to find a solution by merging the ReplaceDialog class (where the signal is emitted) to the ToolBox class, which receives the signal.

During Week 8, the team has the ambition to finish the project.Therefore, before ending this project, I therefore aim to work as much as I can on this project, implementing a Global Search feature, and probably a multitude of smaller features. Each of these features should take less time than before since I have now become familiar with the architecture and logic of our project. After that, it will be time to write the individual report, prepare the defense with the team, and study for the other finals !

## Week 8

After some more work, all is done ! It was a pleasure working on this project, so thanks !
