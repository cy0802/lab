#include<stdio.h>
struct Star{
	int x, y;
};
int main(){
	int n, m, i, j;
	int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
	int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};
	int cnt = 0;
	while(scanf("%d %d", &n, &m) && (n != 0 && m != 0)){
		cnt++;
		int map[105][105] = {0};
		int cntStars = 0;
		struct Star star[5000];
		char ch;
		getchar();
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				ch = getchar();
				if(ch == '-') map[i][j] = 0;
				else{
					map[i][j] = -1;
					star[cntStars].x = i;
					star[cntStars].y = j;
					cntStars++;
				}
				//printf("%c ", ch);
			}
			//printf("\n");
			getchar();
		}
		for(i = 0; i < cntStars; i++){
			for(j = 0; j < 8; j++){ // 8 direction
				int x = star[i].x + dx[j];
				int y = star[i].y + dy[j];
				if(x < 0 || y < 0 || x >= n || y >= m || map[x][y] == -1) continue;
				map[x][y]++;
			}
		}
		printf("Field #%d:\n", cnt);
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(map[i][j] == -1){
					printf("*");
				} else {
					printf("%d", map[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
		/*for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		for(i = 0; i < cntStars; i++){
			printf("%d: %d, %d\n", i+1, star[i].x, star[i].y);
		}*/
		
	}
	return 0;
}