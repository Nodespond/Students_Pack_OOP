#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

enum Subjects{HISTORY,PHYSICS,MATH,RUSSIAN_LANGUAGE,LITERATURE};
enum MoodFACTOR{SLOW,NORMAL,FAST};
enum ParentROLE{MUM,DAD};

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

        string GetName() {
            return this->Name;
        }

        bool operator ==(const Student& stud2) {
            if (this->Name == stud2.Name and this->Age == stud2.Age and this->Specialization == stud2.Specialization and this->Surname == stud2.Surname)
                return true;
            else return false;
        }

        void Show_Marks(Subjects subject) {
            if (subject == HISTORY) {
                for (int i = 0; i < this->marks->History.size(); i++)
                    cout << this->marks->History[i] << " ";
                cout << endl;
                return;
            }

            if (subject == MATH) {
                for (int i = 0; i < this->marks->Math.size(); i++)
                    cout << this->marks->Math[i] << " ";
                cout << endl;
                return;
            }

            if (subject == RUSSIAN_LANGUAGE) {
                for (int i = 0; i < this->marks->Russian_language.size(); i++)
                    cout << this->marks->Russian_language[i] << " ";
                cout << endl;
                return;
            }

            if (subject == LITERATURE) {
                for (int i = 0; i < this->marks->Literature.size(); i++)
                    cout << this->marks->Literature[i] << " ";
                cout << endl;
                return;
            }

            if (subject == PHYSICS) {
                for (int i = 0; i < this->marks->Physics.size(); i++)
                    cout << this->marks->Physics[i] << " ";
                cout << endl;
                return;
            }
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
    bool Mood ;
    unsigned int MarksCounter;
    MoodFACTOR moodFactor;
public:

    //узнать настроение
    bool GetMood (){
        return Mood;
    }

    void SetMood(bool mood) {
        this->Mood = mood;
    }

    void AddMarkCount(int i) {
        this->MarksCounter += i;
    }


    //default initialization
    Teacher() { Name = "-N-"; Surname = "-N-"; Age = 0; MarksCounter = 0; moodFactor = NORMAL; }
    //initialization
    Teacher(string name, string surname, unsigned int age, Subjects subject,bool mood , MoodFACTOR moodfactor) {
        Name = name;
        Surname = surname;
        Age = age;
        Subject = subject;
        Mood = mood;
        MarksCounter = 0;
        moodFactor = moodfactor;
    }

    bool MoodT() {
        bool button = false;
        srand(time(0));
        switch (this->moodFactor) {
        case NORMAL:
            if (this->MarksCounter % 5 == 0)
                button = true;
            break;
        case SLOW:
            if (this->MarksCounter % 8 == 0) 
                button = true;
            break;
        case FAST:
            if (this->MarksCounter % 3 == 0)
                button = true;
            break;
        default: 
            break;
        }

        if (button) {
            if ((rand() % 10) > 5)
                return true;
            else return false;
        }
        else return this->Mood;
    }

    //выставление оценки студенту
    virtual void SetMarkStudent(Student student, Subjects subject) {
        srand(time(0));
        if (this->Mood == true and student.ifStudentGrateOnSubject(subject)) {
            student.Give_Mark(5, subject);
            MarksCounter++;
            this->Mood = MoodT();
            return;
        }
        if (this->Mood == true and student.ifStudentGrateOnSubject(subject) == false) {
            student.Give_Mark(4, subject);
            MarksCounter++;
            this->Mood = MoodT();
            return;
        }
        if (this->Mood == false and student.ifStudentGrateOnSubject(subject)) {
            if( (rand() % (21)) < 10 )
                student.Give_Mark(5, subject);
            else student.Give_Mark(4, subject);
            MarksCounter++;
            this->Mood = MoodT();
            return;
        }
        if (this->Mood == false and student.ifStudentGrateOnSubject(subject) == false) {
            if ((rand() % (21)) < 10)
                student.Give_Mark(3, subject);
            else student.Give_Mark(2, subject);
            MarksCounter++;
            this->Mood = MoodT();
            return;
        }
    }
};

class HappyTeacher : public Teacher {

public:

    HappyTeacher(string name, string surname, unsigned int age, Subjects subject, MoodFACTOR moodfactor) : Teacher(name, surname, age, subject, true, moodfactor) {};

    void SetMarkStudent(Student student, Subjects subject) {
        student.Give_Mark(5, subject);
        AddMarkCount(1);
        SetMood(MoodT());
    }

};

class BadTeacher : public Teacher {

public:

    //initialization
    BadTeacher(string name, string surname, unsigned int age, Subjects subject, MoodFACTOR moodfactor) : Teacher(name, surname, age, subject, false, moodfactor) {};
    

    void SetMarkStudent(Student student, Subjects subject) {
        student.Give_Mark(2, subject);
        AddMarkCount(1);
        SetMood(MoodT());
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

                    int k = rand() % (this->Students.size() + 1);            //выбираю случайного студента(его индекс)
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

                    int k = rand() % (this->Students.size() + 1);            //выбираю случайного студента(его индекс)
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

class Parent {
    private:
        string Name;
        string Surname;
        ParentROLE ParentRole;
        bool Mood;
        vector<Student> Childrens;
    public:
        //default initialization
        Parent() { Name = "-N-"; Surname = "-N-"; }
        //initialization
        Parent(string name, string surname, ParentROLE parentRole, bool mood) {
            Name = name;
            Surname = surname;
            ParentRole = parentRole;
            Mood = mood;
        }

        bool areChildrensExcellent() {
            if (this->Childrens.size() == 0) {
                cout << "Parent don't have childrens\n";
                return false;
            }

            double Summary = 0.0;
            for (int i = 0; i < this->Childrens.size(); i++) {
                if (Childrens[i].isStudentExcellentSummary() == true)
                    Summary += 5.0;
                else Summary += 4.0;
            }
            if ((Summary / this->Childrens.size()) < 4.5)
                return false;
            else return true;
            
        }

        //add child
        void AddChildren(Student student) {
            this->Childrens.push_back(student);
        }
        //told about...
        void ToldAboutEachOther() {
            if (Childrens.size() == 0) {
                cout << "You don't have any childrens!"<<endl;
                return;
            }   

            for (int i = 0; i < Childrens.size(); i++) {
                if (Childrens[i].isStudentExcellentSummary() == true)
                    cout << Childrens[i].GetName() << " study very well!\n";
                else cout << Childrens[i].GetName() << " - BALBES! \n";
            }

            if (this->Mood == true)
                cout << "They are good childrens! I'm proud of them!\n";
            else cout << "They don't try hard enough\n";
        }

        void ToldAboutSomebody() {
            int childIndex = 0;
            srand(time(0));

            if (this->Childrens.size() == 0) {
                cout << "You don't have any childrens!" << endl;
                return;
            }

            childIndex = rand() % (Childrens.size() + 1);
            if (Childrens[childIndex].isStudentExcellentSummary() == true)
                cout << Childrens[childIndex].GetName() << " - my best child! I love you!\n";
            else cout << Childrens[childIndex].GetName() << " - BALBES\n";

            if (this->Mood == true)
                cout << "I'm proud of them!\n";
            else cout << "Try styding more harder!\n";

        }

        void ToldAboutSummary() {
            if (this->Childrens.size() == 0) {
                cout << "You don't have childrens!";
                return;
            }

            if (areChildrensExcellent() == true)
                cout << "My childrens are so good!\n";
            else cout << "BALBESI\n";

            if (this->Mood == true)
                cout << "UTUTUTUTU\n";
            else cout << "SPINOGRIZI!!!\n";
        }

        void ToldAboutYou(Student student) {
            if (find(this->Childrens.begin(), this->Childrens.end(), student) == this->Childrens.end()) {
                cout << "This children ne tvoy children!\n";
                return;
            }

            if (student.isStudentExcellentSummary() == true)
                cout << "My boy are so good!\n";
            else cout << "BALBES YOU!!!\n";

            if (this->Mood == true)
                cout << "UTUTUTUTU\n";
            else cout << "SPINOGRIZ YOU BESPOLEZNIY!!!\n";

        }

};




int main()
{

    Student student("Vasya","Pupkin",20,"Engeneer");
    Student student2("Igor", "Vaku", 22, "Engeneer");
    Student student3("Vlad", "Copr", 19, "Engeneer");

    Teacher teacher{ "Vasyliy","Antipov",32,HISTORY,1,NORMAL};
    student.Show_Marks(HISTORY);
    student2.Show_Marks(HISTORY);
    student3.Show_Marks(HISTORY);
    vector<Student> t1{ student, student2, student3 };
    //вроде бы все работает,но надо будет проверить (шаг 4)
    Classes History(HISTORY, 505, teacher,t1 );
    History.StartLesson();
    student.Show_Marks(HISTORY);
    student2.Show_Marks(HISTORY);
    student3.Show_Marks(HISTORY);
    //шаг пятый - добрые и злые учителя
    HappyTeacher happyT{ "Ivan","vas",22,HISTORY,FAST };
    BadTeacher badlyT{ "Kost","Inrt",43,MATH,NORMAL};
    //6 этап - ГОТОВ!
    //7 этап - ГОТОВ , но не дэбажил))))


    return 0;
}