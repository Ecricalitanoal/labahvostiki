enum napr { fiit, moais, pmi, bi };
enum statuses { failed, ended, passed };
union marks
{
	int e;
	bool z;
};
struct student
{
	int id, course, debt;
	bool past;
	napr napravlenie;
	statuses status;
	marks** exams = new marks * [8];
	marks** zachet = new marks * [8];
};
void filling(struct student*& stu, int n);
void print(struct student*& stu, int n);
void filling_exams(struct student*& stu, int n);
void new_exam(struct student*& stu, int n);
void sort(struct student*& stu, int n);
void sort_past(struct student*& stu, int& n);
void give_status(struct student*& stu, int n);
void next_course(struct student*& stu, int n);
void next_main(struct student*& stu, int n);
std::string naprav_to_str(napr a);
std::string status_to_str(statuses a);
