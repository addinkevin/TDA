from itertools import combinations
from sys import maxsize

class TSPIterative:
    def __init__(self, costMatrix):
        self.costMatrix = costMatrix
        self.vertexCount = len(costMatrix)
        self.memory = [{} for i in range(self.vertexCount)]
        self.path = [{} for i in range(self.vertexCount)]
        self.initialVertex = -1

    def getSetNumberWithOutVertex(self, setNumber, vertexNumber):
        return setNumber - 2**vertexNumber

    def getSetNumberWithVertex(self,setNumber, vertexNumber):
        return setNumber + 2**vertexNumber

    def getSetNumberFromList(self, vertexList):
        setNumber = 0
        for x in vertexList:
            setNumber += 2**x
        return setNumber

    def run(self,initialVertex):
        self.initialVertex = initialVertex

        vertexList = list(range(self.vertexCount))
        vertexList.remove(self.initialVertex)
        maxValue = maxsize

        for v in vertexList:
            self.memory[v][0] = self.costMatrix[v][self.initialVertex]


        for k in range(1, self.vertexCount-1):
            listToIterate = list(vertexList)
            for u in listToIterate:
                vertexList.remove(u)
                newListSetNumber = self.getSetNumberFromList(vertexList)
                for set in combinations(vertexList,k):
                    actualSetNumber = self.getSetNumberFromList(set)
                    minCost = maxValue
                    minVertex = -1
                    for v in set:
                        nextSet = self.getSetNumberWithOutVertex(actualSetNumber,v)
                        newCost = self.costMatrix[u][v] + self.memory[v][nextSet]

                        if newCost < minCost:
                            minVertex = v
                            minCost = newCost

                    self.memory[u][actualSetNumber] = minCost
                    self.path[u][actualSetNumber] = minVertex

                vertexList.append(u)
        setVertex = 2 ** self.vertexCount - 1
        setVertex = self.getSetNumberWithOutVertex(setVertex, self.initialVertex)
        minCost = maxValue
        minVertex = -1
        for v in vertexList:
            newCost = self.costMatrix[initialVertex][v] + \
                      self.memory[v][self.getSetNumberWithOutVertex(setVertex, v)]

            if newCost < minCost:
                minVertex = v
                minCost = newCost


        self.memory[self.initialVertex][setVertex] = minCost
        self.path[self.initialVertex][setVertex] = minVertex

        return minCost, self.createPathList(self.initialVertex, setVertex)


    def createPathList(self, initialVertex, setNumber):
        pathList = [initialVertex]
        actualVertex = initialVertex
        for i in range(self.vertexCount - 1):
            nextVertex = self.path[actualVertex][setNumber]
            pathList.append(nextVertex)
            setNumber = self.getSetNumberWithOutVertex(setNumber, nextVertex)
            actualVertex = nextVertex

        pathList.append(initialVertex)
        return pathList