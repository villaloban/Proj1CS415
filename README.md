## Group Members: Anthony Villalobos, Ryan Brogan


## AI Usage (Claude)

Per the course AI policy, AI was used **only for plotting code** (`plot.py`) and for help connecting the program's CSV output to that plotting script. All algorithm implementations and operation counting were written by our group.

**Tool:** Claude (Anthropic), Opus 5.5 — Sept 28, 2026

---

### Prompt 1
> alright read my project discreption it currently outputs csvs how do we make this into actual scatterplots

**Response (summary):** Claude wrote `plot.py`, a Python/matplotlib script that reads each CSV (first column = x values, other columns = one series each, header row = legend labels) and saves a scatter plot PNG next to it. A `PLOT_SETTINGS` table at the top sets each plot's title, axis labels, and linear/log scale by filename. Usage: `pip install matplotlib`, then `python3 plot.py`.

### Prompt 2
> if i make a folder where all my csv's go then how when i run them again are they supposed to generate inside the folder

**Response (summary):** In C++, create the folder with `std::filesystem::create_directories("results");` (C++17) and open files as `std::ofstream out("results/fib.csv");`. Opening with `ofstream` overwrites old files on each run. Then run `python3 plot.py results`; PNGs are saved beside their CSVs.

### Prompt 3
> should we create a directory like results/task1_results or results/task2_results

**Response (summary):** Yes. Claude changed `main()` in `plot.py` to use `os.walk` so it finds CSVs in subfolders too. `create_directories("results/task1_results")` makes both levels at once. One command, `python3 plot.py results`, plots every task.

### Prompt 4
> alright how do we go about running this does it automatticaly do it when we call for scatterplot

**Response (summary):** Not automatically — they are separate programs. To automate, add `std::system("python3 plot.py results");` (from `<cstdlib>`) at the end of scatter plot mode, after all CSV files are closed. On Windows the command may be `python` instead of `python3`.

### Prompt 5
> would we do this in the main where if choice == 2?

**Response (summary):** Yes — inside the `choice == 2` branch, after the CSV-generating code, so it doesn't run in user testing mode.

### Prompt 6
> that caused an error when they werent happening before sh: -c: line 1: unexpected EOF while looking for matching `'' the csvs still outputed

**Response (summary):** The shell found an unmatched `'` in the command string — usually from curly/stray quotes when copy-pasting, or a path containing an apostrophe. Fix by retyping the line by hand, or wrapping paths in escaped double quotes (`\"...\"`).

### Prompt 7
> is there a way to get divide by one visiable and not covered

**Response (summary):** `M_one` was hidden under `M_divide_and_conquer` because their counts are nearly identical. Claude updated `plot.py` to draw hollow markers in decreasing sizes and to draw at most `MAX_POINTS` (60) evenly spaced points per series, offset per series so markers interleave. Also noted that the overlap is likely correct (divide-and-conquer that recomputes both halves does n − 1 multiplications) and suggested a log y-scale for task 2 to show `M_constant_factor`'s log n growth.

### Prompt 8
> am i able to export this to include in my readme?

**Response (summary):** Claude produced this section as a Markdown file to paste into the README.


## Code Instructions: In order to run the code since we don't have a makefile we run the command

g++ -std=c++17 -O2 -o proj1 src/*.cpp
this compiles the project and then we run 
./proj1
and this executes it for us.

After that were met with a menu screen 
1) User Mode
2) Scatter Plot Mode
0) Exit

Input resulting in 1 takes you to user mode which bring up this menu 
Which Task? (1/2/3)
and in result will lead you to either inputting values for task 1, 2, or 3. 

However if on main menu screen you type 2, then it will produce scatter plots and csvs for all 3 tasks. 

We run this program on optimization 2 since when inputting a large amount of numbers it speeds up the process quite a bit. 




