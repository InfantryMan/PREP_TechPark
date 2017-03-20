#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Faculty
{
  public:
    Faculty(const Faculty& rhs);
    Faculty(const char* name_fac = nullptr, const char* name_univ = nullptr,
        const int num_workers = 0,
        const int num_students = 0, const char* address = nullptr,
        const char* phone = nullptr);
    ~Faculty();

    void set_name_fac(const char *name_fac);
    void set_name_univ(const char *name_univ);
    void set_num_workers(const int num_workers);
    void set_num_students(const int num_students);
    void set_address(const char* address);
    void set_phone(const char* phone);

    void set_chars_copy(const Faculty &rhs);
    void set_chars_assign(const char* name_fac, 
         const char* name_univ,
         const char* address, 
         const char* phone);

    const char* get_name_fac();
    const char* get_name_univ();
    const int get_num_workers();
    const int get_num_students();
    const char* get_address();
    const char* get_phone();

    void show_name_fac();
    void show_name_univ();
    void show_num_workers();
    void show_num_students();
    void show_address();
    void show_phone();

  private:
    char* name_fac;
    char* name_univ;
    int num_workers;
    int num_students;
    char* address;
    char* phone;
};

Faculty::Faculty(const Faculty& rhs):
  num_workers(rhs.num_workers),
  num_students(rhs.num_students)
{
  set_chars_copy(rhs);
  std::cout << "Faculty copy " << std::endl;
}

Faculty::Faculty(const char *name_fac, const char* name_univ, const int workers,
    const int students, const char *address, const char *phone):
  num_workers(workers),
  num_students(students)
{
  set_chars_assign(name_fac, name_univ, address, phone);
}

void Faculty::set_chars_copy(const Faculty& rhs) 
{
  if (rhs.name_fac) {
    size_t len = strlen(rhs.name_fac) + 1;
    name_fac = new char[len];
    memcpy(name_fac, rhs.name_fac, len);
  }
  if (rhs.name_univ) {
    size_t len = strlen(rhs.name_univ) + 1;
    name_univ = new char[len];
    memcpy(name_univ, rhs.name_univ, len);
  }
  if (rhs.address) {
    size_t len = strlen(rhs.address) + 1;
    address = new char[len];
    memcpy(address, rhs.address, len);
  }
  if (rhs.phone) {
    size_t len = strlen(rhs.phone) +1;
    phone = new char[len];
    memcpy(phone, rhs.phone, len);
  }
}

void Faculty::set_chars_assign(const char* name_fac = nullptr, 
         const char* name_univ = nullptr,
         const char* address = nullptr, 
         const char* phone = nullptr)
{
  if (name_fac) {
    size_t len = strlen(name_fac) + 1;
    this->name_fac = new char[len];
    memcpy(this->name_fac, name_fac, len);
  }
  if (name_univ) {
    size_t len = strlen(name_univ) + 1;
    this->name_univ = new char[len];
    memcpy(this->name_univ, name_univ, len);
  }
  if (address) {
    size_t len = strlen(address) + 1;
    this->address = new char[len];
    memcpy(this->address, address, len);
  }
  if (phone) {
    size_t len = strlen(phone) + 1;
    this->phone = new char[len];
    memcpy(this->phone, phone, len);
  }
}

Faculty::~Faculty()
{
  cout <<"=====Здесь сработал деструктор=====" << endl;
  show_name_fac();
  cout <<"===================================" << endl;
  delete[] name_fac;
  delete[] name_univ;
  delete[] address;
  delete[] phone;
  name_fac = nullptr;
  name_univ = nullptr;
  address = nullptr;
  phone = nullptr;
}

const char* Faculty::get_name_fac() 
{
  return name_fac;
}

const char* Faculty::get_name_univ()
{
  return name_univ;
}

const int Faculty::get_num_workers()
{
  return num_workers;
}
 
const int Faculty::get_num_students()
{
  return num_students;
}

const char* Faculty::get_address() 
{
  return address;
}

const char* Faculty::get_phone() 
{
  return phone;
}

void Faculty::set_num_workers(const int num_workers)
{
  this->num_workers = num_workers;
}

void Faculty::set_num_students(const int num_students)
{
  this->num_students = num_students;
}

void Faculty::set_name_fac(const char *name_fac)
{
  if (name_fac) {
    size_t len = strlen(name_fac) + 1;
    this->name_fac = new char [len];
    memcpy(this->name_fac, name_fac, len);
  }

}

void Faculty::set_name_univ(const char *name_univ)
{
  if (name_univ) {
    size_t len = strlen(name_univ) + 1;
    this->name_univ = new char [len];
    memcpy(this->name_univ, name_univ, len);
  }

}

void Faculty::set_address(const char *address)
{
  if (address) {
    size_t len = strlen(address) + 1;
    this->address = new char [len];
    memcpy(this->address, address, len);
  }
}

void Faculty::set_phone(const char *phone)
{
  if (phone) {
    size_t len = strlen(phone) + 1;
    this->phone = new char [len];
    memcpy(this->phone, phone, len);
  }
}

void Faculty::show_name_fac()
{
  cout << name_fac << " ";
}

void Faculty::show_name_univ()
{
  cout << name_univ << " ";
}

void Faculty::show_num_workers()
{
  cout << num_workers << " ";
}

void Faculty::show_num_students()
{
  cout << num_students << " ";
}

void Faculty::show_address()
{
  cout << address << " ";
}

void Faculty::show_phone()
{
  cout << phone << " ";
}

void input_from_file (ifstream &fin, Faculty moscow_univ [], const int N) 
{
  for (int i = 0; i < N; i++) {
    char buf[50];
    int num_workers;
    int num_students;
   
    fin >> buf;     
  //  cout << buf << endl;
    moscow_univ[i].set_name_fac(buf);
    fin >> buf; 
  //  cout << buf << endl;
    moscow_univ[i].set_name_univ(buf);
    fin >> num_workers;
  //  cout << num_workers << endl;
    moscow_univ[i].set_num_workers(num_workers);
    fin >> num_students;
  //  cout << num_students << endl;
    moscow_univ[i].set_num_students(num_students);
    fin >> buf; 
  //  cout << buf << endl;
    moscow_univ[i].set_address(buf);
    fin >> buf; 
  //  cout << buf << endl;
    moscow_univ[i].set_phone(buf);
  }
}

void faculties_from_one_univ(char* all_faculties, Faculty moscow_univ [], const int N)
{
  char name_univ[50];
  cout << "Enter university name\n";
  cin >> name_univ;
  char* all_faculties_begin = all_faculties;
 
  for (int i = 0; i < N; i++) {
    if (strcmp(name_univ, moscow_univ[i].get_name_univ()) == 0) {
      size_t len = strlen(moscow_univ[i].get_name_fac());
      size_t num = strspn(all_faculties_begin, moscow_univ[i].get_name_fac());
      if (num != len) {
        sprintf(all_faculties, "%s ", moscow_univ[i].get_name_fac());
        all_faculties += len + 1;
      }
    }
  }
  cout << "Faculties from " << name_univ << " are: " << all_faculties_begin << endl;
}

void workers_more_than_said(char* all_faculties, Faculty moscow_univ[], const int N)
{
  int num_workers;
  cout << "Enter the number of workers\n";
  cin >> num_workers;
  char* all_faculties_begin = all_faculties;
  
  for (int i = 0; i < N; i++) 
    if (num_workers < moscow_univ[i].get_num_workers()) {
      sprintf(all_faculties, "%s ", moscow_univ[i].get_name_fac());
      all_faculties += strlen(moscow_univ[i].get_name_fac()) + 1;
    }
  cout << "Faculties with workers more than said are: " << all_faculties_begin << endl;
}

void max_students(char* all_faculties, Faculty moscow_univ[], const int N)
{
  int max_students = -1;
  char* all_faculties_begin = all_faculties;
 
  for (int i = 0; i < N; i++) 
    if (max_students < moscow_univ[i].get_num_students()) 
      max_students = moscow_univ[i].get_num_students();
  
  for (int i = 0; i < N; i++)
    if (max_students == moscow_univ[i].get_num_students()) {
      sprintf(all_faculties, "%s ", moscow_univ[i].get_name_fac());
      all_faculties += strlen(moscow_univ[i].get_name_fac()) + 1;
    }

  cout << "Faculty(ies) with max students are: " << all_faculties_begin << endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s arguments must be 3\n", argv[0]);
    return EXIT_FAILURE;
  }

  ifstream fin;

  fin.open(argv[2]);
  if (!fin.is_open()) {
    cout << "File can't be opened\n";
    return EXIT_FAILURE;
  }

  const int N = atoi(argv[1]);

  Faculty moscow_univ[N];

  input_from_file(fin, moscow_univ, N);
  
  fin.close();

  //cout << endl << endl;
 
  for (int i = 0; i < N; i++) {
    moscow_univ[i].show_name_fac();
    moscow_univ[i].show_name_univ();
    moscow_univ[i].show_num_workers();
    moscow_univ[i].show_num_students();
    moscow_univ[i].show_address();
    moscow_univ[i].show_phone();
    cout << endl;
  } 
  
  char* all_faculties = new char [100];
  
  faculties_from_one_univ(all_faculties, moscow_univ, N);
  
  workers_more_than_said(all_faculties, moscow_univ, N);

  max_students(all_faculties, moscow_univ, N);

  delete[] all_faculties;

  return 0;
}
