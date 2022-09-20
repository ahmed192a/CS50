class Node():
    #def __init__(self, state, parent, action):
    #    self.state = state
    #    self.parent = parent
    #    self.action = action

    def __init__(self, current, movie, source):
        self.current = current
        self.movie = movie
        self.source = source

class StackFrontier():
    def __init__(self):
        self.frontier = []

    def add(self, node):
        self.frontier.append(node)

    #def contains_state(self, state):
    #    return any(node.state == state for node in self.frontier)

    def contains_person(self, person):
        return any(node.current == person for node in self.frontier)

    def empty(self):
        return len(self.frontier) == 0

    def remove(self):
        if self.empty():
            raise Exception("empty frontier")
        else:
            node = self.frontier[-1]
            self.frontier = self.frontier[:-1]
            return node


class QueueFrontier(StackFrontier):

    def remove(self):
        if self.empty():
            raise Exception("empty frontier")
        else:
            node = self.frontier[0]
            self.frontier = self.frontier[1:]
            return node
