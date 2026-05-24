# Terminal-Based Tic-Tac-Toe with AI

A terminal-based Tic-Tac-Toe game written in **C** with a rule-based AI opponent.  
Built as a project for **SE121 – Structured Programming**  
**Daffodil International University (DIU)**

---

## Features

- Play against an AI opponent in the terminal
- AI uses a priority-based strategy (not just random moves)
- Input validation — handles out-of-range and occupied cell errors
- Clean board display after every move
- Lightweight — single `.c` file, no external libraries

---

## AI Strategy

The computer follows this priority order on every move:

| Priority | Action |
|----------|--------|
| 1 | **Win** — complete its own 2-in-a-row |
| 2 | **Block** — stop the player from winning |
| 3 | **Center** — take the center cell |
| 4 | **Corner** — take an available corner |
| 5 | **Random** — pick any remaining cell |

---

## How to Compile & Run

### On Linux / Mac
```bash
gcc tictactoe.c -o tictactoe
./tictactoe
```

### On Windows (GCC / MinGW)
```bash
gcc tictactoe.c -o tictactoe.exe
tictactoe.exe
```

---

## How to Play

1. You are **X**, the computer is **O**
2. Enter a **row (1–3)** and **column (1–3)** when prompted
3. First to get 3 in a row — horizontally, vertically, or diagonally — wins!

### Example board
```
 X | O | X 
---|---|---
   | O |   
---|---|---
 X |   | O 
```

---

## Project Structure

```
tictactoe/
├── tictactoe.c    # Full source code
└── README.md      # Project documentation
```

---

## Concepts Used

- 2D arrays
- Functions
- Loops & conditionals
- Random number generation (`rand`, `srand`)
- Rule-based AI logic

---

## Author

**Fuad Hassan Shiraji**  
BSc in Software Engineering (SWE'46-L) 
Daffodil International University (DIU)
