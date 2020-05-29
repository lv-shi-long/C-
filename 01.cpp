const int N = 15;
int map[N][N];
bool visit[N][N];
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
void end()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cout << map[i][j] << "  ";
		cout << endl;
	}
	system("pause");
	exit(0);
}
int res = 0;
bool check(int x, int y, int num)
{
	for (int ste = 1; ste <= 9; ste++)
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] * ste;
			int ny = y + dy[i] * ste;
			if (nx >= 1 && nx <= 9 && ny >= 1 && ny <= 9)
				if (map[nx][ny] == num) return false;

		}
	int nx = (x - 1) / 3;
	int ny = (y - 1) / 3;
	for (int i = nx * 3 + 1; i <= nx * 3 + 3; i++)
	{
		for (int j = ny * 3 + 1; j <= ny * 3 + 3; j++)
		{
			if (i == x && y == j)continue;
			if (map[i][j] == num) return false;
		}
	}
	return true;
}
void dfs(int x1, int y1)
{

	if (y1 == 10) x1++, y1 = 1;
	res = max(res, x1);
	if (x1 == 10)
	{
		end();
		return;
	}
	if (visit[x1][y1] == true)
		dfs(x1, y1 + 1);
	else
	{
		for (int i = 1; i <= 9; i++)
			if (check(x1, y1, i))
			{
				map[x1][y1] = i;
				dfs(x1, y1 + 1);
				map[x1][y1] = 0;
			}
	}
}
