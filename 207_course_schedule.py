import collections

class Node(object):
    def __init__(self, value):
        self.value = value
        self.edges = []
        self.visited = False

    def __str__(self):
        return str(self.value)

    def get_parents(self):
        parents = []
        for edge in self.edges:
            if edge.dst_node == self:
                parents.append(edge.src_node)
        return parents

    def get_children(self):
        children = []
        for edge in self.edges:
            if edge.src_node == self:
                children.append(edge.dst_node)
        return children

class Edge(object):
    def __init__(self, src, dst):
        self.src_node = src
        self.dst_node = dst

    def __str__(self):
        return str(self.src_node) + ':' + str(self.dst_node)

class Graph(object):
    def __init__(self):
        self.nodes = []
        self.edges = []
        self._node_map = {}

    def add_edge(self, edge):
        src_node = None
        dst_node = None

        if edge[1] in self._node_map.keys():
            src_node = self._node_map[edge[1]]
        if edge[0] in self._node_map.keys():
            dst_node = self._node_map[edge[0]]

        if src_node is None:
            src_node = Node(edge[1])
            self.nodes.append(src_node)
            self._node_map[edge[1]] = src_node
        if dst_node is None:
            dst_node = Node(edge[0])
            self.nodes.append(dst_node)
            self._node_map[edge[0]] = dst_node

        edge = Edge(src_node, dst_node)
        self.edges.append(edge)

        src_node.edges.append(edge)
        dst_node.edges.append(edge)

    def has_cycle(self):
        if len(self.nodes) == 0:
            return False

        queue = collections.deque()
        for node in self.nodes:
            if len(node.get_parents()) == 0:
                queue.appendleft(node)

        visited_nodes = []
        while len(queue)>0:
            node = queue.pop()
            node.visited = True
            visited_nodes.append(node)
            for child in node.get_children():
                can_visit = all([parent.visited for parent in child.get_parents()])
                if can_visit:
                    queue.appendleft(child)

        return len(self.nodes) != len(visited_nodes)


class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = Graph()
        for edge in prerequisites:
            graph.add_edge(edge)
        return not graph.has_cycle()


sol = Solution()
assert sol.canFinish(2, [[1,0]]) == True
assert sol.canFinish(2, [[1,0],[0,1]]) == False
assert sol.canFinish(12, [[2,1],[2,9],[3,1],[4,1],[4,2],[6,3],[7,6],[5,2],[8,4],[8,5],[11,10],[12,10]]) == True
assert sol.canFinish(4, [[2,0],[1,0],[3,1],[3,2],[1,3]]) == False

