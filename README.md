# StateMachineDemo

A small C++ console application designed to explore and reinforce the architecture of finite state machines.

This project is intentionally simple and educational.  
The goal is not to build a production framework, but to create a concrete mental model for:

- State ownership
- Context data
- Transition logic
- Command parsing
- Update loops
- Guard conditions
- Event-driven behavior

---

# Overview

The application simulates a small controller system with several operating states:

```text
Idle
Priming
Running
Fault
Shutdown
```

Commands entered into the console modify system context or request actions.

The state machine evaluates the system state during each update cycle and performs legal transitions based on rules and conditions.

---

# Architecture

```text
Console Input
    ↓
Command Parser
    ↓
Context Updates / Actions
    ↓
State Machine
    ↓
Transition Logic
    ↓
System State Changes
```

---

# Project Structure

```text
StateMachineDemo/
├── include/
│   ├── CommandParser.hpp
│   ├── Context.hpp
│   ├── State.hpp
│   └── StateMachine.hpp
│
├── src/
│   ├── CommandParser.cpp
│   ├── StateMachine.cpp
│   └── main.cpp
│
├── Makefile
└── README.md
```

---

# Concepts Demonstrated

## State Ownership

The `StateMachine` owns and manages the current system state.

```cpp
State currentState;
```

---

## Context Separation

System data exists independently of state logic.

```cpp
struct Context
{
    double pressure;
    double temperature;
    bool faultActive;
};
```

This separation allows the state machine to evaluate system conditions without tightly coupling behavior to input parsing.

---

## Transition Logic

Transitions are evaluated during the update cycle.

Example:

```cpp
if (ctx.pressure > 20.0)
{
    transitionTo(State::Running);
}
```

---

## Guarded Transitions

Certain state changes are intentionally illegal.

Example:

```text
Running -> Shutdown
```

is legal.

```text
Idle -> Shutdown
```

is not.

---

# Build

## Requirements

- Linux
- g++
- make

---

## Compile

```bash
make
```

---

## Run

```bash
./statemachine
```

---

# Console Commands

## System Control

```text
start
stop
reset
quit
```

---

## Fault Injection

```text
fault on
fault off
```

---

## Context Modification

```text
set pressure 25
set temperature 90
```

---

## Status

```text
status
```

---

# Example Session

```text
> start
Transition: Idle -> Priming

> set pressure 25
Transition: Priming -> Running

> fault on
Transition: Running -> Fault

> fault off
Transition: Fault -> Idle
```

---

# Why This Exists

This project was created as a hands-on exercise to reinforce state machine architecture in modern C++.

Rather than relying purely on theory or diagrams, the goal is to create a small system that can be fully understood, modified, extended, and evolved over time.

The project serves as a foundation for future exploration into:

- Transition tables
- Event queues
- Async systems
- Hierarchical state machines
- Embedded control systems
- Robotics control architectures
- RTOS task coordination

---

# Future Ideas

- Timed transitions
- Event queue system
- State transition table
- Hierarchical states
- Logging system
- Unit tests
- UDP or CAN input layer
- GUI visualization
- Async update thread
- JSON configuration

---

# License

MIT License

Use it, modify it, break it, rebuild it.
