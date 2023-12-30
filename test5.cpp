#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
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

        bool operator ==(const Student& stud2) {
            if (this->Name == stud2.Name and this->Age == stud2.Age and this->Specialization == stud2.Specialization and this->Surname == stud2.Surname)
                return true;
            else return false;
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
                if (Summary == 0) return false;
                else if ((Summary / this->marks->History.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == PHYSICS) {
                for (int i = 0; i < this->marks->Physics.size(); i++)
                    Summary += this->marks->Physics[i];
                if (Summary == 0) return false;
                else if ((Summary / this->marks->Physics.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == MATH) {
                for (int i = 0; i < this->marks->Math.size(); i++)
                    Summary += this->marks->Math[i];
                if (Summary == 0) return false;
                else if ((Summary / this->marks->Math.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == RUSSIAN_LANGUAGE) {
                for (int i = 0; i < this->marks->Russian_language.size(); i++)
                    Summary += this->marks->Russian_language[i];
                if (Summary == 0) return false;
                else if ((Summary / this->marks->Russian_language.size()) < 4.5)
                    return false;
                else return true;
            }

            if (subject == LITERATURE) {
                for (int i = 0; i < this->marks->Literature.size(); i++)
                    Summary += this->marks->Literature[i];
                if (Summary == 0) return false;
                else if ((Summary / this->marks->Literature.size()) < 4.5)
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

    //узнать настроение
    bool GetMood() {
        return this->Mood;
    }

    //выставление оценки студенту
    virtual void SetMarkStudent(Student student, Subjects subject) {
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

class HappyTeacher : public Teacher {
private:
    string Name;
    string Surname;
    unsigned int Age;
    Subjects Subject;
    bool Mood;
public:
    HappyTeacher() { Name = "-N-"; Surname = "-N-"; Age = 0; }
    //initialization
    HappyTeacher(string name, string surname, unsigned int age, Subjects subject, bool mood) {
        Name = name;
        Surname = surname;
        Age = age;
        Subject = subject;
        Mood = mood;
    }

    void SetMarkStudent(Student student, Subjects subject) {
        student.Give_Mark(5, subject);
    }

};

class BadTeacher : public Teacher {
private:
    string Name;
    string Surname;
    unsigned int Age;
    Subjects Subject;
    bool Mood;
public:
    BadTeacher() { Name = "-N-"; Surname = "-N-"; Age = 0; }
    //initialization
    BadTeacher(string name, string surname, unsigned int age, Subjects subject, bool mood) {
        Name = name;
        Surname = surname;
        Age = age;
        Subject = subject;
        Mood = mood;
    }

    void SetMarkStudent(Student student, Subjects subject) {
        student.Give_Mark(2, subject);
    }

};


class Classes {
private:
    Subjects Discipline;
    unsigned int ClassRoom;
    Teacher MainTeacher;
public:
    vector<Student> Students;
    //default initialization
    Classes() { ClassRoom = 0; }
    //initialization
    Classes(Subjects discipline, unsigned int room, Teacher teacher, vector<Student> students) {
        Discipline = discipline;
        ClassRoom = room;
        MainTeacher = teacher;
        Students = students;
    }

    //проведение занятия
    void StartLesson() {
        vector<Student> mark_is_stuff;
        int mark_count = 0;
        int students_count = 0;
        srand(time(0));
        if (this->MainTeacher.GetMood() == true) {
            if (this->Students.size() == 1) {
                this->MainTeacher.SetMarkStudent(this->Students[0], this->Discipline);
                return;
            }
            if (this->Students.size() > 1 and this->Students.size() < 5) {
                students_count = (int)this->Students.size() - 1;            //вывел случайное число студентов от кол-ва
                for (int i = 0; i < students_count; i++) {

                    int k = rand() % this->Students.size();            //выбираю случайного студента(его индекс)
                    //если студента нет среди тех,кому уже ставили оценку,то ставлю ее и добавляю студента в вектор
                    if (find(mark_is_stuff.begin(), mark_is_stuff.end(), this->Students[k]) == mark_is_stuff.end()) {
                        this->MainTeacher.SetMarkStudent(this->Students[k], this->Discipline);
                        mark_is_stuff.push_back(this->Students[k]);
                    }

                }
            }
            if (this->Students.size() > 5 ) {
                students_count = (int)this->Students.size() - 2;           //вывел случайное число студентов от кол-ва
                for (int i = 0; i < students_count; i++) {

                    int k = rand() % this->Students.size() + 1;            //выбираю случайного студента(его индекс)
                    //если студента нет среди тех,кому уже ставили оценку,то ставлю ее и добавляю студента в вектор
                    if (find(mark_is_stuff.begin(), mark_is_stuff.end(), this->Students[k]) == mark_is_stuff.end()) {
                        this->MainTeacher.SetMarkStudent(this->Students[k], this->Discipline);
                        mark_is_stuff.push_back(this->Students[k]);
                    }

                }
            }
        }

        if (this->MainTeacher.GetMood() == false) {
            if (this->Students.size() == 1) 
                return;
            
            if (this->Students.size() > 1 and this->Students.size() < 5) {
                if (this->Students.size() == 2)
                    students_count = 1;
                else students_count = 2;            //вывел случайное число студентов от кол-ва

                for (int i = 0; i < students_count; i++) {

                    int k = rand() % this->Students.size();            //выбираю случайного студента(его индекс)
                    //если студента нет среди тех,кому уже ставили оценку,то ставлю ее и добавляю студента в вектор
                    if (find(mark_is_stuff.begin(), mark_is_stuff.end(), this->Students[k]) == mark_is_stuff.end()) {
                        this->MainTeacher.SetMarkStudent(this->Students[k], this->Discipline);
                        mark_is_stuff.push_back(this->Students[k]);
                    }

                }
            }
            if (this->Students.size() > 5) {
                students_count = 3;           //вывел случайное число студентов от кол-ва
                for (int i = 0; i < students_count; i++) {

                    int k = rand() % this->Students.size() + 1;            //выбираю случайного студента(его индекс)
                    //если студента нет среди тех,кому уже ставили оценку,то ставлю ее и добавляю студента в вектор
                    if (find(mark_is_stuff.begin(), mark_is_stuff.end(), this->Students[k]) == mark_is_stuff.end()) {
                        this->MainTeacher.SetMarkStudent(this->Students[k], this->Discipline);
                        mark_is_stuff.push_back(this->Students[k]);
                    }

                }
            }
        }

    }




};


int main()
{

    Student student("Vasya","Pupkin",20,"Engeneer");
    Student student2("Igor", "Vaku", 22, "Engeneer");
    Student student3("Vlad", "Copr", 19, "Engeneer");

    Teacher teacher{ "Vasyliy","Antipov",32,HISTORY,1};
    student.Show_Marks(HISTORY);
    student2.Show_Marks(HISTORY);
    student3.Show_Marks(HISTORY);
    vector<Student> t1{ student, student2, student3 };
    //вроде бы все работает,но надо будет проверить
    Classes History(HISTORY, 505, teacher,t1 );
    History.StartLesson();
    student.Show_Marks(HISTORY);
    student2.Show_Marks(HISTORY);
    student3.Show_Marks(HISTORY);

    HappyTeacher happyT{ "Ivan","vas",22,HISTORY};
    BadTeacher badlyT{ "Kost","Inrt",43,MATH};
    badlyT.SetMarkStudent(student3, HISTORY);
    student3.Show_Marks(HISTORY);
    happyT.SetMarkStudent(student3, HISTORY);
    student3.Show_Marks(HISTORY);
    return 0;
}