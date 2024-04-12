//#include <iostream>
//#include <vector>
//#include <fstream>
//#include "MyFuncs.h"
//
//class Student
//{
//    std::string m_first = "";
//    std::string m_last = "";
//    int         m_sid = 0;
//    int         m_grade = 0;
//
//public:
//    Student(){}
//
//    Student(std::string first, std::string last, int sid, int grade)
//        : m_first(first)
//        , m_last(last)
//        , m_sid(sid)
//        , m_grade(grade)
//    {
//        
//    }
//
//    std::string getFirst()
//    {
//        return m_first;
//    }
//
//    std::string getLast()
//    {
//        return m_last;
//    }
//
//    int getSid() {
//        return m_sid;
//    }
//    int getGrade() {
//        return m_grade;
//    }
//
//    void print()
//    {
//        std::cout << m_first + " " + m_last + " " + str(m_sid) + " " + str(m_grade) + "\n";
//    }
//    ~Student()
//    {
//        std::cout << "S destruct\n";
//    }
//};
//
//class Pivo
//{
//    std::string name = "";
//    double alc = 0;
//    double density = 0;
//    bool filtered = true;
//    bool dark = false;
//public:
//    Pivo()
//    {}
//    Pivo(std::string name, double alc, double density, bool filtered, bool dark)
//            :name(name)
//            ,alc(alc)
//            ,density(density)
//            ,filtered(filtered)
//            ,dark(dark)
//    {
//    }
//    ~Pivo()
//    {
//        std::cout << "P destruct\n";
//    }
//
//
//    double get_alc()
//    {
//        return alc;
//    }
//    std::string get_name()
//    {
//        return name;
//    }
//    double get_density()
//    {
//        return density;
//    }
//    std::string get_filtered()
//    {
//        if (filtered)
//        {
//            return "Filtered";
//        }
//        else
//        {
//            return "Unfiltered";
//        }
//    }
//    std::string get_dark()
//    {
//        if (dark)
//        {
//            return "Dark";
//        }
//        else
//        {
//            return "Light";
//        }
//
//    }
//    void print()
//    {
//        std::cout << name
//            << " " << alc
//            << " " << density
//            << " " << get_filtered()
//            << " " << get_dark()
//            << "\n";
//    }
//};
//
//class Course
//{
//    std::vector<Student> m_students;    
//    std::vector<Pivo*> m_pivo;    
//    std::string          m_name;
//
//public:
//    Course(const std::string& name)
//        :m_name(name)
//    {
//
//    }
//
//    void addStudent(const Student& s)
//    {
//        m_students.push_back(s);
//    }
//
//
//    void addPivo(Pivo * s)
//    {
//        m_pivo.push_back(s);
//    }
//
//    void deletePivo()
//    {
//        for (Pivo* p : m_pivo)
//        {
//            delete p;
//        }
//    }
//
//    std::vector<Student> &getStudents()
//    {
//        return m_students;
//    }
//
//    Pivo * getPivo(int index)
//    {
//        return m_pivo[index];
//    }
//
//    std::vector<Pivo*> &getAllPivo()
//    {
//        return m_pivo;
//    }
//
//    void print()
//    {
//        std::vector<Pivo*> pivas = getAllPivo();
//        for (Pivo * p : pivas)
//        {
//           p[0].print();
//        }
//    }
//
//    void addPivoFromFile(const std::string& filename)
//    {
//        std::ifstream fin(filename);
//
//        std::string name;
//        double alc, density;
//        bool filtered, dark;
//        while (fin >> name)
//        {
//            fin >> alc>> density>> filtered>> dark;
//
//            addPivo(new Pivo(name, alc, density, filtered, dark));
//        }
//    }
//
//    ~Course()
//    {
//        std::cout << "C destruct\n";
//        deletePivo();
//    }
//};
//
//int main(int argc, char* argv[])
//{
//
//    Course c("comp404");
//    c.addPivoFromFile("Pivo.txt");
//    c.print();
//
//
//
//
//
//    
//    std::vector<Pivo*> Pivasiki;
//    Pivo bud("Bud", 5, 12, true, false);
//    Pivo shemrok("Shemrok", 6.5, 15, true, true);
//    Pivasiki.push_back(&bud);
//    Pivasiki.push_back(&shemrok);
//    for (size_t i = 0; i < Pivasiki.size(); i++)
//    {
//        Pivasiki[i][0].print();
//    }
//    
//    for (Pivo * p : Pivasiki)
//    {
//        p[0].print();
//    }
//
//     //c.deletePivo();
//
//
//    return 0;
//}
