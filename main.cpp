#include<iostream>
using namespace std;

namespace Merge
{
	int a[101], sorted[101];

	void merge(int left, int right) {
		int mid;
		int p1, p2, p3;

		if (left < right) {
			mid = (left + right) / 2;
			merge(left, mid);
			merge(mid + 1, right);
			p1 = left; // 정렬된 왼쪽 배열에 대한 인덱스
			p2 = mid + 1; // 정렬된 오른쪽 리스트에 대한 인덱스
			p3 = left; // 합병될 리스트에 대한 인덱스
			//분할정렬된 배열의 합병
			while (p1 <= mid && p2 <= right) {
				if (a[p1] < a[p2]) sorted[p3++] = a[p1++];
				else sorted[p3++] = a[p2++];
			}
			// 남아 있는 왼쪽 배열 일괄 복사
			while (p1 <= mid) sorted[p3++] = a[p1++];

			// 남아 있는 오른쪽 배열 일괄 복사
			while (p2 <= right) sorted[p3++] = a[p2++];

			//배열 sorted를 배열 a로 재복사
			for (int i = left; i <= right; i++) {
				a[i] = sorted[i];
			}
		}
	}

	int main() {
		int n, i;
		cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
		}
		merge(1, n);
		for (i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

namespace Quick
{
	int a[100];

	void quickSort(int start, int end) {
		if (start >= end) {	//원소가 1개인 경우 
			return;
		}
		int key = start;	//키는 첫번째 원소 <- 이게 피벗
		int left = start + 1;	//왼쪽 출발 지점 <- 앞에서 큰거
		int right = end;		//오른쪽 출발 지점 <- 뒤에서 작은거
		int temp;			// 스왑을 위한 임시 변수

		while (left <= right) {	//엇갈릴 때까지 반복 
			while (a[left] <= a[key] && left <= right) {	//키 값보다 큰 값을 만날 때까지 
				left++;
			}
			while (a[right] >= a[key] && right > start) {	//키 값보다 작은 값을 만날 때까지 
				right--;
			}
			if (left >= right) {	//현재 만나거나 엇갈린 상태면 키 값과 교체
				temp = a[right];
				a[right] = a[key];
				a[key] = temp;
			}
			else {		//엇갈리지 않았다면 i와 j를 교체
				temp = a[left];
				a[left] = a[right];
				a[right] = temp;
			}
		}
		quickSort(start, right - 1);
		quickSort(right + 1, end);
	}

	int main() {
		int n, i;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		quickSort(0, n - 1);

		for (i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

namespace Insertion
{
	int main()
	{
		int a[100], n, tmp, i, j;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 1; i < n; i++) {
			tmp = a[i];
			for (j = i - 1; j >= 0; j--) {
				if (a[j] > tmp) a[j + 1] = a[j];
				else break;
			}
			a[j + 1] = tmp;
		}
		for (i = 0; i < n; i++) {
			cout << a[i]<< " ";
		}
		return 0;
	}
}

namespace Selection
{
	int main() {
		int a[101], n, tmp, idx, i, j;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n - 1; i++) {
			idx = i;
			for (j = i + 1; j < n; j++) {
				if (a[j] < a[idx]) idx = j;
			}
			tmp = a[i];
			a[i] = a[idx];
			a[idx] = tmp;
		}
		for (i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

namespace Count
{
	int main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		int n;
		cin >> n;
		int data = 0;
		int cnt[10001] = { 0 };

		for (int i = 0; i < n; i++) {
			cin >> data;
			cnt[data]++;
		}

		for (int i = 1; i < 10001; i++) {
			while (cnt[i] != 0) {
				cout << i << " ";
				cnt[i]--;
			}
		}
	}
}

namespace Bubble
{
	int main() {
		int a[101], n, i, j, tmp;
		cin >> n; 
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}
		for (i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

namespace Radix
{
#include <queue>
#define BUCKETS 10
#define DIGITS 3

	std::queue<int>q[10];
	int num[100];

	void radix_sort(int size) {
		int i = 0, factor = 1;

		for (int d = 0; d < DIGITS; d++)
		{
			for (int j = 0; j < size; j++)
			{
				q[(num[j] / factor) % 10].push(num[j]);
			}

			for (int k = 0; k < BUCKETS; k++)
			{
				while (q[k].size())
				{
					num[i++] = q[k].front();
					q[k].pop();
				}
			}
			factor *= 10;
			i = 0;
		}
	}

	int main() {
		int size;
		cin >> size;
		for (int i = 0; i < size; i++) {
			cin >> num[i];
		}
		radix_sort(size);
		for (int i = 0; i < size; i++) {
			cout << num[i] << " ";
		}
	}
}

int main()
{
	return Quick::main();
}