<h1>🚗 carBase: Dynamic Car Data Management System</h1>

<p>
A command-line program written in <strong>C</strong> that manages car inventory using a dynamic linked list. Designed for the fictional company <em>oneCarSolution</em>, the program allows users to add, search, sort, and remove car records in real-time through a structured, modular, and interactive interface.
</p>

<hr />

<h2>📌 Problem Statement</h2>
<p>
Car companies need a fast and flexible system to keep track of their inventory. This project solves that by creating a robust menu-driven tool that stores car data in a linked list and allows users to manage it efficiently via command-line interactions.
</p>

<hr />

<h2>✅ Features</h2>

<ol>
  <li>Add a new car (with unique auto-generated carId)</li>
  <li>Load car data from a file</li>
  <li>Print all cars</li>
  <li>Print the nth car in the list</li>
  <li>Search by carId</li>
  <li>Search by model and type</li>
  <li>Count total number of cars</li>
  <li>Sort cars by carId (ascending)</li>
  <li>Remove a specific car by position</li>
  <li>Remove all cars (with confirmation)</li>
  <li>Exit</li>
</ol>

<p>
Each feature is implemented as its own C source file and uses a shared header file <code>headerA3.h</code> for function prototypes and struct definitions.
</p>

<hr />

<h2>🛠 Tech Stack</h2>

<table>
  <tr><td><strong>Language</strong></td><td>C (C99)</td></tr>
  <tr><td><strong>Data Structure</strong></td><td>Singly Linked List</td></tr>
  <tr><td><strong>Compiler Flags</strong></td><td>-std=c99 -Wall</td></tr>
  <tr><td><strong>Build Tool</strong></td><td>Makefile</td></tr>
</table>

<hr />

<h2>📁 Folder Structure</h2>

<pre><code>
Dynamic-Car-Data-Management-Project/
├── bin/         # Compiled executable (carBase) goes here
├── include/     # headerA3.h
├── src/         # All function implementation .c files + mainA3.c
├── makefile     # Main makefile in the root directory
</code></pre>

<hr />

<h2>📥 How to Download and Run</h2>

<h4>🔧 Requirements</h4>
<ul>
  <li>GCC compiler with C99 support</li>
  <li>Unix/macOS terminal or Git Bash on Windows</li>
  <li>Make installed</li>
</ul>

<h4>📦 Clone the Repository</h4>

<pre><code>
# Step 1: Clone the repository
git clone https://github.com/gcheema05/Dynamic-Car-Data-Management-Project.git

# Step 2: Navigate into the project directory
cd Dynamic-Car-Data-Management-Project
</code></pre>

<h4>▶️ Build and Run</h4>

<pre><code>
# Step 3: Build using make
make carBase

# Step 4: Run the program
./bin/carBase

# Optional: Clean all object and executable files
make clean
</code></pre>

<p><strong>Note:</strong> The makefile compiles all .c files in <code>src/</code> using the header in <code>include/</code> and outputs the executable to <code>bin/carBase</code>.</p>

<hr />

<h2>💾 Example Structure Definition</h2>

<pre><code>
struct car {
    int year;
    double price;
    char model[MAX_LENGTH];
    char type[MAX_LENGTH];
    int carId;
    struct car *nextCar;
};
</code></pre>

<p>
carId is automatically generated using ASCII sums and string lengths and is validated to be unique within the list.
</p>

<hr />

<h2>🧪 Testing</h2>

<p>
All functionality is tested via <code>mainA3.c</code> using input prompts. Edge cases such as invalid car positions and duplicate IDs are handled with validation and regeneration logic.
</p>

<hr />

<h2>🚀 Future Enhancements</h2>
<ul>
  <li>💾 Add functionality to export car list to a file (e.g., CSV format)</li>
  <li>♻️ Implement doubly linked lists for better data navigation</li>
  <li>📊 Support for sorting by year or price</li>
  <li>📁 Support for saving and loading user sessions</li>
  <li>🧪 Automated unit testing support for each function</li>
</ul>
