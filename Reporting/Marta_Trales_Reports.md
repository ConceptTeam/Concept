## WEEK 1--------------------------

We have split the project into main parts - representing its main features and functionalities. 
Everyone is assigned one or more of these parts - we are aiming to create a functional base by everyone working at the same time and then merge together into working on the same target. 

For the moment, we are developing the following:
- Databases and Handling - how the input is stored into the database: Peter, Alex and Marta 
- Text Editor: Bruno, Sacha 
- Search and Organization - Keeping track of the contents of the database and return it upon user search: Peter
- Timer and Focus Tracking - Implement a timer (start, stop, pause etc) and predict possible outcomes by the already existing data: Klaara
- User Interface: Andreea and Milana
- User Input Handling: Raluca and Max
- Feedback System - From already existing data create daily, weekly or on request feedbacks: Max 
- Sync System: Hung and Nguyen Vu
- Kernel: Alex and Octave
- To Do Lists - basic Notion feature: Hung and Nguyen Vu

We are defining classes - to have a better structural view of our project - and possible templates.
We plan on starting actual coding in week 2.

## WEEK 2--------------------------

At Hung's suggestion, we have restructured the team a bit, we have mege some parts into just frontend, backend and infrastructure.

Max and I have managed to install, activate and run the project and its required tools on our teammates laptops. This also helped us understand how the components work together and which files build what.

Personally, I have been working on analysing classes (hierarchy) and templates can help me implement the help section, how they'll connect with the other parts of the app. I plan on implementing this into code the next week and also tie it to the already existing ui. 

## WEEK 3--------------------------

Backend is doing nice progress, databases are being implemented and properly handled. The ui team is solving the bugs across devices.
We had the problem of a Qt version change - some libraries din not build properly, so we switched back to a callable app (no web anymore).
We had to reconfigure some laptops, but with the already gained experience it all went smoothly.

We had to rethink our texteditor and now we have a second header into the main collumn and a button that triggers a new window of texteditor.

Personal work:
 - I have implemented a way for the contents to fit into each screen (adapt by the width and height of each) - contribution to Screen01.ui.qml (Now main.qml)
 - Reordered Help and Search button (in ui) in order to implement the Help Section + rearranged the buttons. (main.qml)

 - Tried implementing the Help Section as a dropdown in qml but could not align the items. 
 Documented options in cpp and understood the scheme for that. 
 Will implement it all in cpp - Week 4 (with few additions in qml).
 

## WEEK 4--------------------------

Backend has been implemented into the Concept Project (it's been initially developed individually).
We have observed and analysed problems for the Windows users in the team. Solutions to these issues were found and the project follows its normal course. 

The timer is currently being implemented, together with its features. To-do lists are also being put into place and will be soon functional + their qml tools.

Personal work:
- Implemented the dropdown menu, alligned, options and functional
- (+ Break Week 1 ) Implemented the first option in the dropdown menu
- (+ Break Week 2 ) Implemented the second option in the dropdown menu


## Week 5-------------------------- 

The ui and whole appearence (and parts of structure) of the project - mainly interface - have been changed and improved. We have a totally new theme, dark, with catchier and more modern appearence, together with clearer buttons and intuitive architecture.

This meant, however, that I had to redo the help section. The dropdown menu was still functional, but its options and their implementations had to be totally rewritten and rethought too.
I suggested the implementation of the Help Section Options as dialogue windows and the team agreed, so I proceeded with the research on how Dialog windows work in Qt (there is a type for them).

I therefore implemented the first two options of the dropdown menu:
    - The File option consists of a dialog window with a list of all the features in the File dropdown from top left corner.
    - The Notebooks option is a short resume of what the Notebooks files consists of


## Week 6--------------------------

The project is getting closer and closer to its final form. Everyone has clear task after the last 2 lectures, the teams seems more glued than ever. The missing parts are clear, the possible imprivements are being signaled, the work is going great!

Personally, I continued with the Help Section. I implemented the section dedicated to the Timer - again a list for all the features. I have also completed the File option with the View and Edit features, I added them and their definitions into the list. 

As Andreea and Bruno had worked on a new feature - the Calendare - I got the task to verify it. After some testing around, I realised that the window was still open even after not in use and/or the whole window app was closed. Thus, I made it close whenever the window app was closed - further functionability was implemented by my teammates.

As my work with the Help Section was almost done and mainyl not soliciting, I decided to get involved in the most pressing feautre being developed: the Timer.
I got familiarised with Klaara's branch and debugged it - it was a pretty tough work but I got it all building, yet no actual counting for the timer. From there on, I let Klaara continue her work on it.
(All my timer contributions appear in Klaara's branch and commit)



## Week 7--------------------------
We got the broadest overview of the project and it all seems to get together. 
I completed the Help Section with options about the last features added and continued my work upon the Timer.

We have a well structured list of the very last features that need to be implemented and have assigned tasks equally to people, in suhc a way that the workload is adecvate for everyone.



## Week 8--------------------------
The very last week got us with a project in really great shape. We just needed to adjust a dew details, make sure each comma and accolade is at its right place... and we are good to go!

Very last updates I did were:
- Edited the qml such that it builds (a faulty accolade)
- Reimplemented the Timer Button on the SideBar and connected it rightly to the Timer block
- Updated the Help Section options accordingly to the current version.

This was an intense, interesting and yet very much enjoyable project. We learnt how to work as a team, how to contribute individually to the whole and also got the chance to assimilate new, useful features and usages for C++. I was and still am incredibly happy and proud with my team, amazing, working and dedicated people who gave this project life.

Thank you!

