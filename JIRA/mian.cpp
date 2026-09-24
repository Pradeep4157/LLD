#include <bits/stdc++.h>
using namespace std;

enum class TaskStatus
{
    TODO,
    IN_PROGRESS,
    DONE
};

enum class TaskPriority
{
    LOW,
    MEDIUM,
    HIGH
};

class User
{
private:
    int id;
    string name;
    // vector<Task *> tasks;

public:
};

class Task
{
private:
    int id;
    string title;
    string description;
    int assigneeUserId;
    TaskStatus status;
    TaskPriority priority;

public:
    Task(int id_, string title_, string description_, TaskPriority priority_)
    {
        priority = priority_;
        id = id_;
        title = title_;
        description = description_;
        status = TaskStatus::TODO;
    }
    void changeTaskStatus(TaskStatus newStatus)
    {
        status = newStatus;
    }
    int getId()
    {
        return id;
    }
    void assignUser(int userId)
    {
        assigneeUserId = userId;
    }
};

class Project
{
private:
    // int nextTaskId;
    int id;
    string name;
    vector<Task *> tasks;
    // vector<User *> members;

public:
    Project(int id_, string name_)
    {
        id = id_;
        name = name_;
    }
    void addTask(int taskId, string title, string description, TaskPriority priority)
    {

        Task *newTask = new Task(taskId, title, description, priority);
        tasks.push_back(newTask);
    }
    int getId()
    {
        return id;
    }
    void assignTask(int taskId, int userId)
    {
        for (auto &task : tasks)
        {
            if (task->getId() == taskId)
            {
                task->assignUser(userId);
            }
        }
    }
};

class TaskManager
{
private:
    int nextProjectId;
    int nextTaskId;
    int id;
    string name;
    vector<Task *> tasks;
    vector<Project *> projects;
    vector<User *> users;
    unordered_map<int, int> taskToProject;

public:
    TaskManager()
    {
        nextTaskId = 0;
        nextProjectId = 0;
    }
    void creatProject(string name)
    {
        int newProjectId = nextProjectId++;
        Project *project = new Project(newProjectId, name);
        projects.push_back(project);
    }
    void createTask(int projectId, string title, string description, TaskPriority priority)
    {
        for (auto &project : projects)
        {
            int currentId = project->getId();
            if (currentId == projectId)
            {
                // this is the project where we need to add this new task..
                int newTaskId = nextTaskId;
                taskToProject[newTaskId] = projectId;
                nextTaskId++;
                project->addTask(newTaskId, title, description, priority);
            }
        }
    }
    void assignTask(int taskId, int userId)
    {
        int projectId = taskToProject[taskId];
        for (auto &project : projects)
        {
            int currentId = project->getId();
            if (currentId == projectId)
            {
                // send the data..
                project->assignTask(taskId, userId);
            }
        }
    }
    void changeTaskStatus(int taskId, TaskStatus newStatus)
    {
        int projectId = taskToProject[taskId];
        for (auto &project : projects)
        {
        }
    }
    void getTask(int taskId) {}
};

signed main()
{
}