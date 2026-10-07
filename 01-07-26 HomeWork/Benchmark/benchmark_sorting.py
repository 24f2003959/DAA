import random
import time
import matplotlib.pyplot as plt
def benchmark(sort_functions):
    sizes = [10, 20, 50, 100, 200,  500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000]

    for sort_func in sort_functions:
        times = []

        for size in sizes:
            arr = []
            for i in range(size):
                arr.append(random.randint(0, 100000))

            start = time.perf_counter()
            sort_func(arr.copy())
            end = time.perf_counter()

            times.append(end - start)

        plt.plot(sizes, times, marker='o', label=sort_func.__name__)

    plt.title("Sorting Algorithm Comparison")
    plt.xlabel("Array Size")
    plt.ylabel("Execution Time (seconds)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()