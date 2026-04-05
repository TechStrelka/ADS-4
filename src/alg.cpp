// Copyright 2021 NNTU-CS
int binSearch(int *arr, int left, int right, int value) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid;
        if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int countPairs1(int *arr, int len, int value) {
    int count = 0;
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
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int temp = right;
            while (temp > left && arr[left] + arr[temp] == value) {
                count++;
                temp--;
            }
            left++;
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
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        int res = binSearch(arr, i + 1, len - 1, target);
        if (res != -1) {
            count++;
            int l = res - 1;
            while (l > i && arr[l] == target) {
                count++;
                l--;
            }
            int r = res + 1;
            while (r < len && arr[r] == target) {
                count++;
                r++;
            }
        }
    }
    return count;
}
