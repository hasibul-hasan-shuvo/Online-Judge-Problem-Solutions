#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}

};

class Student :  public Person{
	private:
		vector<int> marks;
        int totalMark;
        int average;
	public:
        Student(string firstName, string secondName, int id, vector <int> marks) : Person(firstName, secondName, id){
            this->marks = marks;
        }

        char calculate(){
            for(int index = 0; index < marks.size(); index++)
                totalMark += marks[index];
            average = totalMark/marks.size();
            if(average >= 90) {
                return 'O'; // Outstanding
            }
            else if(average >= 80) {
                return 'E'; // Exceeds Expectations
            }
            else if(average >= 70) {
                return 'A'; // Acceptable
            }
            else if(average >= 55) {
                return 'P'; // Poor
            }
            else if(average >= 40) {
                return 'D'; // Dreadful
            }
            else {
                return 'T'; // Troll
            }
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}