#include <iostream>
#include <string>
#include <map>

using namespace std;

// Class to represent tutoring service
class TutoringService
{
private:

    // Mapping of student grade level to tutor availability
    map<int, string> tutorAvailability;

public:

    // Constructor
    TutoringService()
    {
        // Initialize mapping by setting availability to false for all grade levels
        for (int i = 0; i <= 12; i++)
        {
            tutorAvailability[i] = "Unavailable";
        }
    }

    // Method to add a tutor to the system
    void addTutor(int gradeLevel, string tutorId)
    {
        tutorAvailability[gradeLevel] = tutorId;
    }

    // Method to remove a tutor from the system
    void removeTutor(int gradeLevel)
    {
        tutorAvailability[gradeLevel] = "Unavailable";
    }

    // Method to check availability of tutor for a given grade level
    bool isTutorAvailable(int gradeLevel)
    {
        if (tutorAvailability[gradeLevel] == "Unavailable")
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // Method to get the ID of the tutor for a given grade level
    string getTutorId(int gradeLevel)
    {
        if (isTutorAvailable(gradeLevel))
        {
            return tutorAvailability[gradeLevel];
        }
        else
        {
            return "";
        }
    }
};

// Main function to use tutoring service
int main() 
{
    // Create instance of tutoring service
    TutoringService service;

    // Add tutors to tutoring service
    service.addTutor(7, "Susan123");
    service.addTutor(9, "Mitch456");
    service.addTutor(12, "John789");

    // Check if tutor is available for grade level 9
    if (service.isTutorAvailable(9))
    {
        cout << "Tutor is available for grade level 9." << endl;
        cout << "The tutor ID is: " << service.getTutorId(9) << endl;
    }
    else
    {
        cout << "Tutor is not available for grade level 9." << endl;
    }

    return 0;
}