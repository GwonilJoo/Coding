#include<cstdio>

int n, ans = 10000, S[21][21];
bool visit[21];

int getmin(int a, int b) { return a < b ? a : b; }

int getabs(int a) { return a >= 0 ? a : -a; }

void calc() {
	int start_sum = 0, link_sum = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i]) {
			for (int j = 1; j <= n; j++) {
				if (visit[j]) {
					start_sum += S[i][j];
				}
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				if (!visit[j]) {
					link_sum += S[i][j];
				}
			}
		}
	}

	//printf("%d %d\n", start_sum, link_sum);

	ans = getmin(ans, getabs(start_sum - link_sum));
}

void dfs(int cur, int cnt) {
	// 체크인
	visit[cur] = true;
	//printf("%d %d\n", cur, cnt);

	// 목적지?
	if (cnt == n / 2) {
		// 최솟값 계산
		calc();

		visit[cur] = false;
		return;
	}

	// 순회
	for (int next = cur+1; next <= n; next++) {
		// 갈 수 있는가?
		if (visit[next]) continue;

		// 간다
		dfs(next, cnt + 1);
	}

	// 체크아웃
	visit[cur] = false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	dfs(1, 1);

	printf("%d\n", ans);
}
