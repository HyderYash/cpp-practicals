#include <iostream>
#include <string>
using namespace std;

class ApplicationSettings {
private:
    string theme;
    ApplicationSettings() : theme("Light") {}

public:
    static ApplicationSettings& getInstance() {
        static ApplicationSettings instance;
        return instance;
    }

    ApplicationSettings(const ApplicationSettings&) = delete;
    ApplicationSettings& operator=(const ApplicationSettings&) = delete;

    void setTheme(const string& value) {
        theme = value;
    }

    string getTheme() const {
        return theme;
    }
};

int main() {
    cout << "Name: Yash Sharma\nRoll No: E25B000411\n\n";
    ApplicationSettings& first = ApplicationSettings::getInstance();
    ApplicationSettings& second = ApplicationSettings::getInstance();

    cout << boolalpha;
    cout << "Same object: " << (&first == &second) << '\n';
    cout << "Initial theme: " << first.getTheme() << '\n';
    first.setTheme("Dark");
    cout << "Theme through first reference: " << first.getTheme() << '\n';
    cout << "Theme through second reference: " << second.getTheme() << '\n';
    return 0;
}
