#pragma once

class Program {
Utils Utils;
private:
    void PrintMainMenu(void) {
        Utils.ClearConsole();
        cout <<
            "--------------------\n" <<
            "| 1 - exit         |\n" <<
            "| 2 - Encode       |\n" <<
            "| 3 - Decode       |\n" <<
            "--------------------\n";
    }
    int ChoiceOption(void) {
        string choiceBuffer;
        string okChars = "0123456789";
        cout << ">>> ";
        getline(cin, choiceBuffer);
        int userChoice = Utils.StrToInt(choiceBuffer);
        if (userChoice == -1) {
            return -1;
        }
        if (userChoice > 3 || userChoice < 1) {
            return -1;
        }
        return userChoice;
    }
public:
    int Main(void) {
        Encode Encode;
        Decode Decode;
        while (true) {
            PrintMainMenu();
            int userChoice = ChoiceOption();
            if (userChoice == -1) {
                cout << "invalid choice\n";
                Utils.WaitKeyDown();
                continue;
            }
            if (userChoice == 1) {
                break;
            }
            if (userChoice == 2) {
                Encode.init();
            }
            if (userChoice == 3) {
                Decode.init();
            }
        }
        return 0;
    }
};