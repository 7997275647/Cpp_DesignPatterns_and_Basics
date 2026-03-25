# Command Pattern Documentation

## Overview

The **Command Pattern** is a behavioral design pattern that encapsulates a request as an object, thereby allowing you to parameterize clients with different requests, queue requests, and support undoable operations. It decouples the object that invokes an operation from the one that performs it.

In essence, the Command Pattern turns an action or request into a standalone object that contains all the information about the action. This allows you to:
- Pass commands as parameters
- Queue and delay command execution
- Support undo/redo functionality
- Log and audit actions
- Create macro commands (composite commands)

---

## Pattern Structure

### Core Components

1. **Command Interface (Abstract Base Class)**
   - Defines the contract that all concrete commands must follow
   - Declares methods for executing operations (e.g., `execute()`, `undo()`, `clear()`)
   - May also include methods for managing command state

2. **Concrete Command Classes**
   - Implement the Command interface
   - Bind a Receiver object with an action
   - Implement the actual behavior when `execute()` is called
   - Store necessary state and parameters needed for execution and undoing

3. **Receiver**
   - Contains the actual logic that performs the work
   - Called by the Concrete Command to carry out the request
   - Has no knowledge of the Command Pattern itself
   - Can be any object that needs to perform actions

4. **Invoker**
   - Asks the command to carry out its request
   - May store previous commands for undo/redo functionality
   - Initiates the command execution but doesn't handle the actual implementation

5. **Client**
   - Creates concrete command objects
   - Associates them with receivers
   - May configure the invoker with commands

---

## Key Characteristics

### Encapsulation of Requests
Commands encapsulate requests as objects, making them suitable for:
- Parameterization of objects
- Storage in collections
- Transmission over networks

### Decoupling
- The invoker (sender) is decoupled from the receiver
- Classes that invoke operations are independent of classes that perform them
- New commands can be added without modifying existing code

### Flexibility in Execution
Commands can be:
- Executed immediately
- Executed later (deferred execution)
- Executed multiple times
- Queued or scheduled
- Combined into composite commands (Macro Commands)

---

## Real-World Examples

1. **Undo/Redo Functionality**
   - Text editors (undo/redo in Word, VS Code)
   - Image editors (Photoshop history)
   - Each edit operation is a command that can be undone or redone

2. **Task Scheduling**
   - Job schedulers queue commands for later execution
   - Operating system task scheduling

3. **Transaction Systems**
   - Database transactions
   - Financial applications queuing operations for processing

4. **Game Development**
   - Player actions (move, jump, attack) as commands
   - Recording and replaying game actions
   - Input handling and mapping

5. **Remote Control Systems**
   - Smart home automation (commands sent to devices)
   - Television remote controls
   - Device APIs accepting command objects

6. **Macro Recording**
   - Microsoft Office macros
   - Development tools recording user actions

---

## Use Cases

Use the Command Pattern when you need to:

1. **Parameterize objects with operations** - Pass different commands to the same object
2. **Queue operations** - Create command queues for sequential or batch processing
3. **Schedule command execution** - Execute commands at specified times
4. **Support undo/redo operations** - Maintain command history for reversal
5. **Log commands** - Record all commands executed for auditing or recovery
6. **Support user macros** - Allow users to define sequences of commands
7. **Implement modal dialogs with operations** - Dialog boxes that queue actions
8. **Decouple senders from receivers** - Make the system more maintainable and flexible
9. **Implement callback mechanisms** - Replace callbacks with command objects
10. **Support high-level transactions** - Group multiple commands into atomic transactions

---

## Class Diagram Representation

```
        ┌──────────────────┐
        │   <<interface>>  │
        │     Command      │
        ├──────────────────┤
        │ + execute()      │
        │ + undo()         │
        │ + clear()        │
        └────────┬─────────┘
                 △
                 │
      ┌──────────┴──────────┐
      │                     │
  ┌───────────┐         ┌────────┐
  │   Move    │         │  Jump  │
  ├───────────┤         ├────────┤
  │ - data    │         │        │
  │ + execute │         │execute │
  │ + undo    │         │ + undo │
  │ + clear   │         │ + clear│
  └───┬───────┘         └────────┘
      │
      └──→ uses → [Receiver]
```

---

## Benefits

1. **Single Responsibility Principle** - Commands encapsulate a single action responsibility
2. **Open/Closed Principle** - New commands can be added without modifying existing code
3. **Loose Coupling** - Invoker and receiver are decoupled
4. **Flexibility** - Commands can be executed, queued, logged, or undone
5. **Testability** - Commands can be easily tested in isolation
6. **Reusability** - Commands can be reused in different contexts
7. **Command Composition** - Commands can be combined into composite commands

---

## Drawbacks

1. **Increased Complexity** - Adds more classes and objects to the system
2. **Memory Overhead** - Each command object consumes memory, especially with large state
3. **Serialization Challenges** - Complex commands may be difficult to serialize
4. **Undo/Redo State Management** - Storing command history requires careful state management
5. **Performance Considerations** - Creating many command objects may impact performance

---

## Implementation Pattern

### Basic Structure

```cpp
// 1. Define the Command Interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void clear() = 0;
};

// 2. Create Concrete Commands
class Move : public Command {
private:
    MoveData data;
public:
    void execute() override;
    void undo() override;
    void clear() override;
};

// 3. Create Invoker (Command Queue/Manager)
class CommandInvoker {
private:
    std::vector<Command*> commandHistory;
public:
    void execute(Command* command) {
        command->execute();
        commandHistory.push_back(command);
    }
    
    void undo() {
        if (!commandHistory.empty()) {
            commandHistory.back()->undo();
            commandHistory.pop_back();
        }
    }
};
```

### Key Methods

- **execute()** - Performs the command's operation
- **undo()** - Reverses the operation (if applicable)
- **clear()** - Clears command state or resources

---

## Comparison with Similar Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|-----------------|
| **Strategy** | Encapsulates operations for selection | Strategy is about *how* to do something; Command is about *doing* something |
| **Observer** | Notify multiple objects of state change | Observer is push-based; Command is about executing actions |
| **Memento** | Capture and restore object state | Memento captures state; Command captures actions |
| **Chain of Responsibility** | Pass request along a chain | Chain passes requests through handlers; Command encapsulates requests |

---

## Best Practices

1. **Use with Command Queue** - Combine with a command queue for scheduling
2. **Implement Undo Properly** - Store enough state to undo operations
3. **Consider Memory** - Be mindful of memory usage when storing command history
4. **Thread Safety** - Ensure thread-safe command execution in multi-threaded environments
5. **Serialization** - Consider how commands will be serialized if needed
6. **Macro Commands** - Implement composite commands for complex operations
7. **Command Logging** - Log commands for auditing and debugging
8. **Error Handling** - Handle failures gracefully and ensure undo integrity

---

## Summary

The Command Pattern is a powerful design pattern for encapsulating requests as objects. It enables you to:
- Decouple senders from receivers
- Queue, log, and undo operations
- Create flexible and extensible systems
- Implement advanced features like macro recording and transaction management

By using the Command Pattern, you create systems that are more maintainable, testable, and flexible to change. It's particularly valuable in applications requiring undo/redo functionality, command queuing, or complex operation management.
