import matplotlib.pyplot as plt

def dfs(graph, x, y, first, second):
    if graph[x][y] == 1:
        return
    graph[x][y] = 1
    dfs(graph, first, y, first, second)
    dfs(graph, x, second, first, second)
    dfs(graph, 0, y, first, second)
    dfs(graph, x, 0, first, second)
    if second - y > x:
        dfs(graph, 0, x + y, first, second)
    else:
        dfs(graph, x + y - second, second, first, second)
    if first - x > y:
        dfs(graph, x + y, 0, first, second)
    else:
        dfs(graph, first, x + y - first, first, second)

def get_points(first, second):
    graph = [[0 for _ in range (second + 1)] for _ in range(first + 1)]
    dfs(graph, 0, 0, first, second)
    points = []
    for i, row in enumerate(graph):
        for j, value in enumerate(row):
            if value == 1:
                points.append((j, i))
    return points

def plot_graph(points):
    x = [point[0] for point in points]
    y = [point[1] for point in points]
    plt.scatter(x, y)
    plt.show()

if __name__ == "__main__":
    first, second = 1001, 132
    points = get_points(first, second)
    plot_graph(points)
