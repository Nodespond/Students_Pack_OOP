#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

enum Subjects{HISTORY,PHYSICS,MATH,RUSSIAN_LANGUAGE,LITERATURE};

struct Marks {
    vector<unsigned int> History;
    vector<unsigned int> Physics;
    vector<unsigned int> Math;
    vector<unsigned int> Russian_language;
    vector<unsigned int> Literature;
};

class Student {
    private:
        string Name;
        string Surname;
        unsigned int Age;
        string Specialization;
    public:
        Marks* marks;

        //default initialization
        Student() { Name = "-N-"; Surname = "-N-"; Age = 0; Specialization = "-N-"; marks = nullptr; }
        //initialization
        Student(string name, string surname, unsigned int age, string specialise){
            Name = name;
            Surname = surname;
            Age = age;
            Specialization = specialise;
            marks = new Marks;
        }
        //сеттер для специальности
        void SetSpecialization(string specialise) {
            this->Specialization = specialise;
        }
        //геттер для специальности
        string GetSpecialization() {
            return this->Specialization;
        }

        void Show_Marks(Subjects subject) {
            for (int i = 0; i < this->marks->History.size(); i++)
                cout << this->marks->History[i] << " ";
            cout << endl;
        }

        //метод получения оценки
        void Give_Mark(unsigned int mark, Subjects subject) {
            switch (subject) {
                case HISTORY:
                    this->marks->History.push_back(mark);
                    break;
                case PHYSICS:
                    this->marks->Physics.push_back(mark);
                    break;
                case MATH:
                    this->marks->Math.push_back(mark);
                    break;
                case RUSSIAN_LANGUAGE:
                    this->marks->Russian_language.push_back(mark);
                    break;
                case LITERATURE:
                    this->marks->Literature.push_back(mark);
                    break;
                default:
                    cout << "This subject is underfined!";
                    break;
            }
        }
        
        //проверка на то,отличник ли студент по всем предметам
        bool isStudentExcellentSummary() {
            double Summary = 0.0;
            for (int i = 0; i < this->marks->History.size(); i++) {
                Summary += this->marks->History[i];
            }
            if (this->marks->History.size() != 0) {
                if ((Summary / this->marks->History.size()) < 4.5)
                    return false;
                else Summary = 0;
            }
            else return false;

            for (int i = 0; i < this->marks->Physics.size(); i++) {
                Summary += this->marks->Physics[i];
            }
            if (this->marks->Physics.size() != 0) {
                if ((Summary / this->marks->Physics.size()) < 4.5)
                    return false;
                else Summary = 0;
            }
            else return false;

            for (int i = 0; i < this->marks->Math.size(); i++) {
                Summary += this->marks->Math[i];
            }
            if (this->marks->Math.size() != 0) {
                if ((Summary / this->marks->Math.size()) < 4.5)
                    return false;
                else Summary = 0;
            }
            else return false;

            for (int i = 0; i < this->marks->Russian_language.size(); i++) {
                Summary += this->marks->Russian_language[i];
            }
            if (this->marks->Russian_language.size() != 0) {
                if ((Summary / this->marks->Russian_language.size()) < 4.5)
                    return false;
                else Summary = 0;
            }
            else return false;

            for (int i = 0; i < this->marks->Literature.size(); i++) {
                Summary += this->marks->Literature[i];
            }
            if (this->marks->Literature.size() != 0) {
                if ((Summary / this->marks->Literature.size()) < 4.5)
                    return false;
                else Summary = 0;
            }
            else return false;

            return true;
        }

        //отличник ли студент по одному предмету
        bool ifStudentGrateOnSubject(Subjects subject) {
            double Summary = 0.0;
            if (subject == HISTORY) {
                for (int i = 0; i < this->marks->History.size(); i++)
                    Summary += this->marks->History[i];
                if ((Summary / this->marks->History.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == PHYSICS) {
                for (int i = 0; i < this->marks->Physics.size(); i++)
                    Summary += this->marks->Physics[i];
                if ((Summary / this->marks->Physics.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == MATH) {
                for (int i = 0; i < this->marks->Math.size(); i++)
                    Summary += this->marks->Math[i];
                if ((Summary / this->marks->Math.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == RUSSIAN_LANGUAGE) {
                for (int i = 0; i < this->marks->Russian_language.size(); i++)
                    Summary += this->marks->Russian_language[i];
                if ((Summary / this->marks->Russian_language.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == LITERATURE) {
                for (int i = 0; i < this->marks->Literature.size(); i++)
                    Summary += this->marks->Literature[i];
                if ((Summary / this->marks->Literature.size()) < 4.5)
                    return false;
                else return true;
            }
        }


};

class Teacher {
private:
    string Name;
    string Surname;
    unsigned int Age;
    Subjects Subject;
    bool Mood;
public:
    //default initialization
    Teacher() { Name = "-N-"; Surname = "-N-"; Age = 0;  }
    //initialization
    Teacher(string name, string surname, unsigned int age, Subjects subject,bool mood) {
        Name = name;
        Surname = surname;
        Age = age;
        Subject = subject;
        Mood = mood;
    }

    //выставление оценки студенту
    void SetMarkStudent(Student student, Subjects subject) {
        srand(time(0));

        if (this->Mood == true and student.ifStudentGrateOnSubject(subject)) {
            student.Give_Mark(5, subject);
            return;
        }
        if (this->Mood == true and student.ifStudentGrateOnSubject(subject) == false) {
            student.Give_Mark(4, subject);
            return;
        }
        if (this->Mood == false and student.ifStudentGrateOnSubject(subject)) {
            if( (rand() % (21)) < 10 )
                student.Give_Mark(5, subject);
            else student.Give_Mark(4, subject);
            return;
        }
        if (this->Mood == false and student.ifStudentGrateOnSubject(subject) == false) {
            if ((rand() % (21)) < 10)
                student.Give_Mark(3, subject);
            else student.Give_Mark(2, subject);
            return;
        }
    }
};




int main()
{
    Student student("Vasya","Pupkin",20,"Engeneer");
    Student student2("Igor", "Vaku", 22, "Engeneer");

    student.Give_Mark(4, HISTORY);
    student.Give_Mark(5, HISTORY);
    student.Give_Mark(4, PHYSICS);
    student.Give_Mark(5, PHYSICS);
    student.Give_Mark(4, MATH);
    student.Give_Mark(5, MATH);
    student.Give_Mark(4, RUSSIAN_LANGUAGE);
    student.Give_Mark(5, RUSSIAN_LANGUAGE);
    student.Give_Mark(4, LITERATURE);
    student.Give_Mark(5, LITERATURE);
    cout << student.isStudentExcellentSummary()<<endl;  //выведет true
    student2.Give_Mark(4, HISTORY);
    student2.Give_Mark(3, HISTORY);
    student2.Give_Mark(4, PHYSICS);
    student2.Give_Mark(5, PHYSICS);
    student2.Give_Mark(4, MATH);
    student2.Give_Mark(5, MATH);
    student2.Give_Mark(4, RUSSIAN_LANGUAGE);
    student2.Give_Mark(5, RUSSIAN_LANGUAGE);
    student2.Give_Mark(4, LITERATURE);
    student2.Give_Mark(5, LITERATURE);
    cout << student2.isStudentExcellentSummary() << endl;  //выведет false
    student2.Show_Marks(HISTORY);
    Teacher teacher{ "Vasyliy","Antipov",32,HISTORY,0 };
    teacher.SetMarkStudent(student2, HISTORY);
    student2.Show_Marks(HISTORY);
    return 0;
}