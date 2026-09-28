"""
plot.py - turns the CSVs from scatter plot mode into scatter plots (PNG).

Usage:
    python3 plot.py                # plots every .csv in the current folder
    python3 plot.py results/       # plots every .csv in a given folder

CSV format expected (one file per plot):
    first column  = x values (k or n)
    other columns = one series each (y values), header row = legend labels

    e.g.  n,Selection Sort,Insertion Sort
          100,4950,99
          200,19900,199

Requires: pip install matplotlib
"""
import csv
import os
import sys

import matplotlib
matplotlib.use("Agg")  # no window needed, just save PNGs
import matplotlib.pyplot as plt

# Per-file axis settings: filename -> (title, x label, y label, x scale, y scale)
# Rename the keys to match YOUR CSV filenames. Scales: "linear" or "log".
PLOT_SETTINGS = {
    "fib.csv":          ("Task 1a: Recursive Fibonacci additions A(k)",
                         "k", "A(k) (additions)", "linear", "log"),
    "gcd.csv":          ("Task 1b: Euclid's GCD worst case D(n)",
                         "n = Fib(k)", "D(n) (modulo divisions)", "log", "linear"),
    "exp.csv":          ("Task 2: Exponentiation multiplications M(n)",
                         "n", "M(n) (multiplications)", "linear", "log"),
    "sort_best.csv":    ("Task 3: Best case (sorted input)",
                         "n (list size)", "C(n) (comparisons)", "linear", "linear"),
    "sort_average.csv": ("Task 3: Average case (random input)",
                         "n (list size)", "C(n) (comparisons)", "linear", "linear"),
    "sort_worst.csv":   ("Task 3: Worst case (reverse sorted input)",
                         "n (list size)", "C(n) (comparisons)", "linear", "linear"),
}

MARKERS = ["o", "s", "^", "D", "v"]


def read_csv(path):
    with open(path, newline="") as f:
        rows = [r for r in csv.reader(f) if r and r[0].strip()]
    header, data = rows[0], rows[1:]
    x = [float(r[0]) for r in data]
    series = {}
    for col in range(1, len(header)):
        series[header[col].strip()] = [float(r[col]) for r in data]
    return header[0].strip(), x, series


def plot_file(path):
    name = os.path.basename(path)
    x_name, x, series = read_csv(path)
    title, xlabel, ylabel, xscale, yscale = PLOT_SETTINGS.get(
        name, (name[:-4], x_name, "count", "linear", "linear"))

    fig, ax = plt.subplots(figsize=(8, 5))
    for i, (label, y) in enumerate(series.items()):
        # log scales can't show 0, so drop those points on log axes
        pts = [(a, b) for a, b in zip(x, y)
               if (xscale != "log" or a > 0) and (yscale != "log" or b > 0)]
        ax.scatter([p[0] for p in pts], [p[1] for p in pts],
                   s=18, marker=MARKERS[i % len(MARKERS)], label=label)

    ax.set_title(title)
    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.set_xscale(xscale)
    ax.set_yscale(yscale)
    ax.grid(True, which="both", alpha=0.3)
    if len(series) > 1:
        ax.legend()

    out = path[:-4] + ".png"
    fig.tight_layout()
    fig.savefig(out, dpi=150)
    plt.close(fig)
    print(f"saved {out}")


def main():
    folder = sys.argv[1] if len(sys.argv) > 1 else "."
    # walk the folder AND its subfolders (e.g. results/task1_results/)
    csvs = sorted(os.path.join(root, f)
                  for root, _, files in os.walk(folder)
                  for f in files if f.endswith(".csv"))
    if not csvs:
        print(f"no .csv files found in {folder}")
        return
    for path in csvs:
        plot_file(path)


if __name__ == "__main__":
    main()
