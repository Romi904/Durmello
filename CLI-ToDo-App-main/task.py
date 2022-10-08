import sys

priority_list = []
task_list = []
completed_list = []

try:
    taskfile = open('task.txt', 'r+')
    for task in taskfile.readlines():
        priority = ([int(p) for p in task.split() if p.isdigit()][0])
        task_list.append(' '.join(task.split()[1:]))
        priority_list.append(priority)
    taskfile.close()
except FileNotFoundError:
    taskfile = open('task.txt', 'w+')
    taskfile.close()

try:
    completed_file = open('completed.txt', 'r+')
    for comp_task in completed_file.readlines():
        completed_list.append(comp_task.rstrip())
    completed_file.close()
except FileNotFoundError:
    completed_file = open('completed.txt', 'w+')
    completed_file.close()

def show_help():
  print("""Usage :-
    $ ./task add 2 hello world    # Add a new item with priority 2 and text "hello world" to the list
    $ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order
    $ ./task del INDEX            # Delete the incomplete item with the given index
    $ ./task done INDEX           # Mark the incomplete item with the given index as complete
    $ ./task help                 # Show usage
    $ ./task report               # Statistics""")

def add_task(priority, text):
    priority = int(priority)
    i = 0
    for i in range(len(priority_list)):
        if(priority_list[i] > priority):
            priority_list.insert(i, priority)
            task_list.insert(i, text)
            break
    if(i == len(priority_list)-1 or i == 0):
        priority_list.append(priority)
        task_list.append(text)
    taskfile = open('task.txt', 'w')
    for i in range(len(priority_list)):
        taskfile.write("{} {}\n".format(priority_list[i], task_list[i]))
    taskfile.close()
    print('Added task: "{}" with priority {}'.format(text, priority))

def list_tasks():
    for i in range(len(priority_list)):
        print("{}. {} [{}]".format(i+1, task_list[i], priority_list[i]))

def del_task(index):
    index = int(index)
    try:
        task_list.pop(index-1)
        priority_list.pop(index-1)
        taskfile = open('task.txt', 'w')
        for i in range(len(priority_list)):
            taskfile.write("{} {}\n".format(priority_list[i], task_list[i]))
        taskfile.close()
        print("Deleted item with index {}".format(index))
    except IndexError:
        print("Error: item with index {} does not exist. Nothing deleted.".format(index))

def done_task(index):
    try:
        index = int(index)
        file1 = open("completed.txt", "a")
        file1.write("{}\n".format(task_list[index-1]))
        file1.close()
        del task_list[(index-1)]
        del priority_list[(index-1)]
        taskfile = open('task.txt', 'w')
        for i in range(len(priority_list)):
            taskfile.write("{} {}\n".format(priority_list[i], task_list[i]))
        taskfile.close()
        print("Marked item as done.")
    except IndexError:
        print("Error: no incomplete item with index {} exists.".format(index))

def report():
    print("Pending: {}".format(len(priority_list)))
    for i in range(len(priority_list)):
        print("{}. {} [{}]".format(i+1, task_list[i], priority_list[i]))
    print("\nCompleted: {}".format(len(completed_list)))
    for i in range(len(completed_list)):
        print("{}. {}".format(i+1, completed_list[i]))

try:
    if(sys.argv[1]=='add'):
        add_task(sys.argv[2], sys.argv[3])
    elif(sys.argv[1]=='ls'):
        list_tasks()
    elif(sys.argv[1]=='del'):
        del_task(sys.argv[2])
    elif(sys.argv[1]=='done'):
        done_task(sys.argv[2])
    elif(sys.argv[1]=='report'):
        report()
    else:
        show_help()
except IndexError:
    show_help()


