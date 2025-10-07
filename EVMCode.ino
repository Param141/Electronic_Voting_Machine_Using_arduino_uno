#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (Address: 0x27, Columns: 16, Rows: 2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BJP 8
#define CONGRESS 9
#define AAP 10

int bjpVotes = 0;
int congressVotes = 0;
int aapVotes = 0;
const int winningThreshold = 5;  // Votes required to win

void setup() {
    // LCD setup
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("EVM Ready");

    // Button setup (Use external 10KΩ pull-down resistors)
    pinMode(BJP, INPUT_PULLUP);
    pinMode(CONGRESS, INPUT_PULLUP);
    pinMode(AAP, INPUT_PULLUP);

    // Serial Monitor
    Serial.begin(9600);
    Serial.println("EVM Ready");
}

void loop() {
    // BJP button pressed
    if (buttonPressed(BJP)) {
        bjpVotes++;
        Serial.print("BJP Vote: ");
        Serial.println(bjpVotes);
        updateDisplay();
    }

    // Congress button pressed
    if (buttonPressed(CONGRESS)) {
        congressVotes++;
        Serial.print("Congress Vote: ");
        Serial.println(congressVotes);
        updateDisplay();
    }

    // AAP button pressed
    if (buttonPressed(AAP)) {
        aapVotes++;
        Serial.print("AAP Vote: ");
        Serial.println(aapVotes);
        updateDisplay();
    }

    // Check for winner
    if (bjpVotes >= winningThreshold) {
        displayWinner("BJP Wins");
    } 
    else if (congressVotes >= winningThreshold) {
        displayWinner("Congress Wins");
    } 
    else if (aapVotes >= winningThreshold) {
        displayWinner("AAP Wins");
    }
}

// Function to check button press with debounce
bool buttonPressed(int buttonPin) {
    if (digitalRead(buttonPin) == LOW) {
        delay(50);  // Debounce delay
        if (digitalRead(buttonPin) == LOW) {
            while (digitalRead(buttonPin) == LOW); // Wait for button release
            delay(50);  // Another debounce
            return true;
        }
    }
    return false;
}

void updateDisplay() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BJP: ");
    lcd.print(bjpVotes);
    lcd.print(" CNG: ");
    lcd.print(congressVotes);

    lcd.setCursor(0, 1);
    lcd.print("AAP: ");
    lcd.print(aapVotes);

    Serial.print("Current Votes -> BJP: ");
    Serial.print(bjpVotes);
    Serial.print(", Congress: ");
    Serial.print(congressVotes);
    Serial.print(", AAP: ");
    Serial.println(aapVotes);
}

void displayWinner(String winner) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(winner);
    Serial.println(winner);

    delay(5000);  // Show result for 5 seconds

    // Reset votes after showing the winner
    bjpVotes = 0;
    congressVotes = 0;
    aapVotes = 0;

    // Reset LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("EVM Ready");
    Serial.println("EVM Reset");
}