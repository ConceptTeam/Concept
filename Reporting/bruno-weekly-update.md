## Week 1:
For the first week, I did research on how I should be able to make the 
text editor. The idea should first to create a terminal text editor and
then from it adapt it to qt-creator.

https://viewsourcecode.org/snaptoken/kilo/

I also look up for some libraries that could help me doing it. such as ncurses.

https://www.linuxjournal.com/content/getting-started-ncurses

## week 2:
I advanced in creating the text editor, but i still haven't commited to repo because:

1) to many bugs because i was relying too much on chat gpt to create the text editor

2) I was learning how to use the qt libraries;

From now on, it seem that it will be more fluid since i have learned better how to use qt, especially the <Qapplication>

the idea of creating first a terminal editor was also very bad, because i won't be able to adapt most of it to qt. And ncurses is not so good for gui purposes

## week 3:

Finished making a prototype for the text editor, and started working with gui directly. I suggested the idea of maybe substuting the entire
qml for cpp by using a mix of Qwidgets and QmainWindow libraries in cpp. We will try to put this idea in practice for the next week.

## Week 4: 

Added some more features in the main page, such as a button to open more than one text editor.

## week 5:

Worked on the reduction of the qml code, and in integrating some qt libraries functionalities.

## Week 6:

Started working on creating a calendar that holds events. This created some issues since the way that the QCalendarWidget works is a little bit weird.
once it does not hold objects.

Added some more features in the main page, such as a button to open more than one text editor.

## Week 7:

Finished calendar and integrated it to the database, so that it holds the events even though the app is reinitialized. 
Also, integrated timer to the database. So information of the timer is hold by the system for further applications, such as the time spent for focus and time spent for break.

Also, verified many pull requests and a lot of code correction. Including typos that would make the project not build properly.

CMakelists.txt was corrected.

## Week 8:

reviwing most of the pull resquest, including solving conflicts. Also, deleted some files from a merge of "Klaara_Timer2.0" branch that were creating some conflicts with the Main bthe Main branch.
