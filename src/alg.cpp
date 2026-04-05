// Copyright 2021 NNTU-CS
void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[left + (right - left) / 2];
    int l = left;
    int r = right;
    while (l <= r) {
        while (arr[l] < pivot) {
            l++;
        }
        while (arr[r] > pivot) {
            r--;
        }
        if (l <= r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }
    if (left < r) {
        quickSort(arr, left, r);
    }
    if (l < right) {
        quickSort(arr, l, right);
    }
}
int binSearch(int* arr, int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid;
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    quickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
int count = 0;
    quickSort(arr, 0, len - 1);
    for (int i = 0; i < len; ++i) {
        int search = value - arr[i];
        if (binSearch(arr, search, i + 1, len - 1) != -1) {
            ++count;
        }
    }
    return count;
}
