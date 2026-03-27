#ifndef COMMANDPATTERN_HPP
#define COMMANDPATTERN_HPP

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void clear() = 0;
};

class Move : public Command
{
public:
    void execute() override;
    void undo() override;
    void clear() override;
};

class Jump : public Command
{
public:
    void execute() override;
    void undo() override;
    void clear() override;
};

void testCommandPattern();

#endif // COMMANDPATTERN_HPP