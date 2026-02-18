import numpy as np
import time
import pandas as pd
import sys

# Increase recursion depth for deep QuickSort calls on large arrays
sys.setrecursionlimit(200000)

# --- 1. DATA GENERATION ---
scales = [100, 1000, 10000, 100000, 150000]
data_dict = {}

for s in scales:
    # Generating random integers between 0 and 1,000,000
    arr = np.random.randint(0, 1000000, size=s)
    data_dict[s] = arr

# Saving to an .npy file
np.save("random_data.npy", data_dict)
print("Data saved to random_data.npy")

# --- 2. SORTING ALGORITHMS ---

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]; i += 1
            else:
                arr[k] = R[j]; j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]; i += 1; k += 1
        while j < len(R):
            arr[k] = R[j]; j += 1; k += 1

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + right

def heapify(arr, n, i):
    largest = i
    l, r = 2 * i + 1, 2 * i + 2
    if l < n and arr[i] < arr[l]: largest = l
    if r < n and arr[largest] < arr[r]: largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1): heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def radix_sort(arr):
    if len(arr) == 0: return arr
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        n = len(arr)
        output = [0] * n
        count = [0] * 10
        for i in range(n):
            index = arr[i] // exp
            count[index % 10] += 1
        for i in range(1, 10):
            count[i] += count[i - 1]
        i = n - 1
        while i >= 0:
            index = arr[i] // exp
            output[count[index % 10] - 1] = arr[i]
            count[index % 10] -= 1
            i -= 1
        for i in range(len(arr)): arr[i] = output[i]
        exp *= 10

# --- 3. EXECUTION AND TIMING ---

algorithms = {
    "Insertion": insertion_sort,
    "Bubble": bubble_sort,
    "Merge": merge_sort,
    "Selection": selection_sort,
    "Quick": quick_sort,
    "Heap": heap_sort,
    "Radix": radix_sort
}

results = []

for scale in scales:
    print(f"Testing Scale: {scale}...")
    for name, func in algorithms.items():
        # Load a fresh copy of the array for each test
        test_arr = data_dict[scale].copy()
        
        start_time = time.time()
        if name == "Quick":
            test_arr = func(test_arr)
        else:
            func(test_arr)
        end_time = time.time()
        
        duration = end_time - start_time
        results.append({"Scale": scale, "Algorithm": name, "Time (s)": round(duration, 5)})

# --- 4. EXPORTING TO EXCEL/CSV ---

# Creating a grid (Pivot Table)
df = pd.DataFrame(results)
pivot_df = df.pivot(index="Algorithm", columns="Scale", values="Time (s)")

# Export
pivot_df.to_csv("sorting_results.csv")

print("\n--- Execution Times (Seconds) ---")
print(pivot_df)
print("\nFiles 'sorting_results.csv' and 'sorting_results.xlsx' have been created.")