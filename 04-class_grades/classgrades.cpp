#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

const char *classmenu = R"(
#####################################
#      Class Grades Management      #
# --------------------------------- #
#                                   #
# 1. Display All Grades             #
# 2. Show The Best Grade            #
# 3. Calculate Class Average Grade  #
# 4. Get List of Failed Students    #
# 0. Exit                           #
#####################################)";

struct result_t
{
    std::string name;
    double grade;
};

enum menu_item
{
    exit_item,
    display_all_item,
    show_best_grade_item,
    calculate_average_grade_item,
    get_failed_list_item,
};

std::vector<result_t> class_result;

std::vector<result_t> openfileasvector(std::string path)
{
    std::string line;
    std::string name;
    double grade;

    std::ifstream reader(path);

    if (!reader)
    {
        std::cout << "Error opening input file"
                  << "\n";
        exit(-1);
    }

    for (int i = 0; !reader.eof(); i++)
    {
        std::getline(reader, line);
        std::stringstream s(line);
        s.str(line);
        s >> grade;
        s >> name;

        class_result.push_back({name, grade});
    }

    reader.close();
    return class_result;
}

void display_grades(const std::vector<result_t> result)
{

    for (auto i : result)
    {
        std::cout << i.grade << '\t' << i.name << '\n';
    }
}
void show_best_grade(const std::vector<result_t> result)
{
    float max_grade = 0;
    int max_grade_index;
    result_t max_result;
    for (auto i : result)
    {
        if (i.grade > max_grade)
        {
            max_grade = i.grade;
            max_result = i;
        }
    }
    std::cout << "The Best Grade is " << max_result.grade << " from " << max_result.name << '\n';
}
void calculate_average_grade(const std::vector<result_t> result)
{
    float sum = 0;
    
    int index = 0;
    result_t max_result;
    for (auto i : result)
    {
        index++;
        sum += i.grade;
    }
    float average {sum/index};
    std::cout << "Class average grade is" << '\t' << average << '\n';
}
void get_list_of_failed_student(const std::vector<result_t> result)
{
     std::vector<result_t> failed_student_result;
    for (auto i : result)
    {
        if(i.grade < 10) 
        failed_student_result.push_back({i.name, i.grade});
    }
    std :: cout << "Failed Students: \n";
    display_grades(failed_student_result);
}

int main(int argc, char *argv[])
{

    std::string file_path{"grades.txt"};
    if (argc == 2)
    {
        file_path = argv[1];
    }
    else if (argc >= 2)
    {
        std::cout << "Extra input ";
        exit(-1);
    }

    std ::cout << classmenu;
    int item;

    auto class_result = openfileasvector(file_path);

    while (1)
    {
        std ::cout << "\n Select Command >";
        std ::cin >> item;
        switch (item)
        {
        case exit_item:
            return 0;
            break;

        case display_all_item:
            display_grades(class_result);
            break;

        case show_best_grade_item:
            show_best_grade(class_result);
            break;

        case calculate_average_grade_item:
            calculate_average_grade(class_result);
            break;

        case get_failed_list_item:
            get_list_of_failed_student(class_result);
            break;

        default:
            break;
        }
    }

    return 0;
}