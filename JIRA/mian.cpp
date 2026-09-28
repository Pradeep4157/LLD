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
    User(int id_, string name_)
    {
        id = id_;
        name = name_;
    }
    int getId()
    {
        return id;
    }
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
        assigneeUserId = -1;
    }

    int getId()
    {
        return id;
    }
    void assignUser(int userId)
    {
        assigneeUserId = userId;
    }
    void changeStatus(TaskStatus newStatus)
    {
        status = newStatus;
    }
};

class Project
{
private:
    // int nextTaskId;
    int id;
    string name;
    vector<Task *> tasks;
    vector<User *> members;

public:
    Project(int id_, string name_)
    {
        id = id_;
        name = name_;
    }

    //........................Task.........................................

    void addTask(int taskId, string title, string description, TaskPriority priority)
    {

        Task *newTask = new Task(taskId, title, description, priority);
        tasks.push_back(newTask);
    }

    bool assignTask(int taskId, int userId)
    {
        if (memberExists(userId) == false)
            return false;
        for (auto &task : tasks)
        {
            if (task->getId() == taskId)
            {
                task->assignUser(userId);
                return true;
            }
        }
        return false;
    }
    bool deleteTask(int taskId)
    {
        int index = -1;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i]->getId() == taskId)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
            return false;
        delete tasks[index];
        tasks.erase(tasks.begin() + index);
        return true;
    }

    bool taskExists(int taskId)
    {
        for (auto &task : tasks)
        {
            if (task->getId() == taskId)
                return true;
        }
        return false;
    }
    bool changeTaskStatus(int taskId, TaskStatus newStatus)
    {
        Task *task = getTask(taskId);
        if (task == nullptr)
            return false;
        task->changeStatus(newStatus);
        return true;
    }
    Task *getTask(int taskId)
    {
        for (auto &task : tasks)
        {
            if (task->getId() == taskId)
            {
                return task;
            }
        }
        return nullptr;
    }

    //.......................Members..........................................
    void addMember(User *user)
    {
        members.push_back(user);
    }
    bool removeMember(User *user)
    {
        if (memberExists(user->getId()) == false)
            return false;
        int idx = -1;
        for (int i = 0; i < members.size(); i++)
        {
            if (user->getId() == members[i]->getId())
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return false;
        members.erase(members.begin() + idx);
        return true;
    }
    bool memberExists(int userId)
    {
        for (auto &user : members)
        {
            if (user->getId() == userId)
                return true;
        }
        return false;
    }
    int getId()
    {
        return id;
    }
};

class TaskManager
{
private:
    int nextProjectId;
    int nextTaskId;
    int nextUserId;
    // int id;
    // string name;
    vector<Task *> tasks;
    vector<Project *> projects;
    vector<User *> users;

public:
    TaskManager()
    {
        nextTaskId = 0;
        nextProjectId = 0;
        nextUserId = 0;
    }
    // .................................User...............................................
    int createUser(const string &name)
    {
        int newUserId = nextUserId + 1;
        nextUserId++;
        User *newUser = new User(nextUserId, name);
        users.push_back(newUser);
        return newUserId;
    }
    bool userExists(int userId)
    {
        for (auto &user : users)
        {
            if (user->getId() == userId)
                return true;
        }
        return false;
    }

    //...............................Project..................................................

    int creatProject(string name)
    {
        int newProjectId = nextProjectId++;
        Project *project = new Project(newProjectId, name);
        projects.push_back(project);
        return newProjectId;
    }
    Project *getProject(int projectId)
    {
        for (auto &project : projects)
        {
            if (project->getId() == projectId)
            {
                return project;
            }
        }
        return nullptr;
    }

    //...............................MemberShip.................................................

    bool addMember(int userId, int projectId)
    {
        Project *project = getProject(projectId);
        if (project == nullptr)
            return false;
        for (auto &user : users)
        {
            if (user->getId() == userId)
            {
                if (project->memberExists(userId))
                    return false;
                project->addMember(user);
                return true;
            }
        }
        return false;
    }

    bool memberExists(int memberId)
    {
        for (auto &member : users)
        {
            if (member->getId() == memberId)
                return true;
        }
        return false;
    }

    bool removeMember(int userId, int projectId)
    {
        Project *project = getProject(projectId);
        if (project == nullptr)
            return false;
        if (project->memberExists(userId) == false)
            return false;
        for (auto &user : users)
        {
            if (user->getId() == userId)
            {
                project->removeMember(user);
                return true;
            }
        }
        return false;
    }

    //....................Task.............................................

    int createTask(int projectId, string title, string description, TaskPriority priority)
    {
        Project *project = getProject(projectId);
        if (project == nullptr)
            return -1;
        int newTaskId = nextTaskId;
        nextTaskId++;
        project->addTask(newTaskId, title, description, priority);
        return newTaskId;
    }

    bool assignTask(int taskId, int userId)
    {
        if (!memberExists(userId))
            return false;
        Project *currentProject = nullptr;
        for (auto &project : projects)
        {
            if (project->taskExists(taskId))
            {
                currentProject = project;
                break;
            }
        }
        if (currentProject == nullptr)
            return false;
        return currentProject->assignTask(taskId, userId);
    }
    bool changeTaskStatus(int taskId, TaskStatus newStatus)
    {
        Task *currentTask = getTask(taskId);
        if (currentTask == nullptr)
            return false;
        currentTask->changeStatus(newStatus);
        return true;
    }
    Task *getTask(int taskId)
    {
        Task *task = nullptr;
        for (auto &project : projects)
        {
            if (project->taskExists(taskId))
            {
                return project->getTask(taskId);
            }
        }
        return nullptr;
    }

    bool deleteTask(int taskId)
    {
        Project *currentProject = nullptr;
        for (auto &project : projects)
        {
            if (project->taskExists(taskId))
            {
                currentProject = project;
                break;
            }
        }
        if (currentProject == nullptr)
            return false;
        return currentProject->deleteTask(taskId);
    }
};

signed main()
{
}