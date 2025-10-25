# Electronic_Voting_Machine_Using_arduino_uno

Objective:
To build a simple electronic voting machine using an Arduino Uno board.


Components Required:
Arduino Uno
16x2 LCD
Push buttons
Power Supply
Connecting wires
Multipurpose PCB
Circuit Diagram and Working Principle:

In this project, we use three push buttons, each representing a different candidate. While the number of candidates can be increased, it's limited to three here for simplicity.
When a voter presses one of the three buttons, the vote count for the corresponding candidate increments by one. After all votes are cast, the candidate with more than 40% of the votes, or the highest number of votes overall, is declared the winner. The final result is displayed on the 16x2 LCD.
The Arduino is the core of the project, controlling all processes, including:


Reading the push button inputs.
Incrementing the vote counts.
Calculating the result.
Displaying the votes and final result on the LCD.
Circuit Connections
The circuit for this project is quite straightforward:
Push Buttons: The three push buttons are connected directly to Arduino pins A1 (15), A2 (16), and A3 (17), with the other end connected to ground.
16x2 LCD: The LCD is connected to the Arduino in 4-bit mode.


Control Pins:
RS to Arduino pin 12.
RW to GND
En to Arduino pin 11
Data Pins:
D4 to Arduino pin 5
D5 to Arduino pin 4
D6 to Arduino pin 3
D7 to Arduino pin 2
