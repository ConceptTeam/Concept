Week 1:

We met with the team to discuss our roles. I planned out what kind of features we could implement and started searching for pre-existing simple c++ implementations of these features.
- timer: set focus time, collect data for total duration of focus time, implement pause/quit/continue
- to-do list: add and complete tasks
- focus tracking: set goals for day/week/month, follow progress, collect stats (time, words typed, tasks completed)

Took on the timer implementation as my responsibility. Created framework for a class of Timer objects.

Week 2:

Medically excused absence from classes and coursework.

Week 3:

Defined more functions for the timer. Researched and used the std::chrono library to simplify how time is tracked and stored by class timer items.

Week 4:

Discussed the storing of timer-related data with Alex. Realized in the TD (after discussing with a TA and my team members) that my implementation of the timer was not compatible with our app, and started rewriting it. (My functions involved while loops that would prohibit the rest of the app from responding to user interaction.)

Vacation:

Tested the functions and attributes of the Timer class, pushed my work so far into klaara_timer branch.

Week 5:

Returned to work with my timer, tried to connect my Timer class in c++ directly to the ui with qml buttons. After working on it for some time realized it wasn't plausible. (Later realized it was best to create a new class inheriting from QObject)

In the mean time, created a strictly visual timer in qml (does not track/store time spent). (branch qml_timer)

Also pushed a c++ version of the timer that was improved but not connected to the ui (experimented with Q_objects). This version was debugged by Marta and Andreea.

Week 6:

Integrated my cpp files with the most recent version of our project in a new branch Klaara_Timer2.0 and debugged the conflicts.

Connected a simple implementation of the timer to the UI
- start, stop, break, continue button functionalities as expected
- set focus period: define how long u want to work -> starts a count down timer
- no focus period set -> starts a count up timer from zero
- timer tracks how long youve worked

Week 7:

Added features to timer: (branch Klaara_Timer2.0)
- debugged timetracking: timer tracks how long the timer has been running and how long youve been on break (this data stored into database by Bruno's implementation)
- User can choose break length from dropdown menu (or choose 'until continued') and the timer display will be replaced by a break timer
- the focus timer automatically continues when break timer ends / is ended by the user.


  

