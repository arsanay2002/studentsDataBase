#include <gtest/gtest.h>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

void addStudent(std::vector<Student>& database, const Student& student) {
    database.push_back(student);
}

int countStudents(const std::vector<Student>& database) {
    return static_cast<int>(database.size());
}

// Юнит-тесты функций addStudent и countStudents
TEST(UnitTest, AddStudentIncreasesSize) {
    std::vector<Student> db;
    EXPECT_EQ(countStudents(db), 0);

    addStudent(db, {"Alice", 20, "CS", 3.5});
    EXPECT_EQ(countStudents(db), 1);

    addStudent(db, {"Bob", 22, "Math", 3.8});
    EXPECT_EQ(countStudents(db), 2);
}

TEST(UnitTest, CountStudentsEmpty) {
    std::vector<Student> db;
    EXPECT_EQ(countStudents(db), 0);
}

// Тесты функциональности базы данных студентов
TEST(DatabaseTest, StudentsAreStoredCorrectly) {
    std::vector<Student> db;
    Student s = {"Alice", 20, "CS", 3.5};
    addStudent(db, s);

    ASSERT_EQ(db.size(), 1);
    EXPECT_EQ(db[0].name, "Alice");
    EXPECT_EQ(db[0].age, 20);
    EXPECT_EQ(db[0].major, "CS");
    EXPECT_DOUBLE_EQ(db[0].gpa, 3.5);
}

TEST(DatabaseTest, CountStudentsMultipleAdd) {
    std::vector<Student> db;
    for (int i = 0; i < 5; i++) {
        addStudent(db, {"Student" + std::to_string(i), 18 + i, "Major" + std::to_string(i), 3.0 + i});
    }
    EXPECT_EQ(countStudents(db), 5);
}

TEST(DatabaseTest, GPAValuesAccuracy) {
    std::vector<Student> db;
    addStudent(db, {"Test", 30, "Physics", 4.0});
    EXPECT_DOUBLE_EQ(db[0].gpa, 4.0);
}
