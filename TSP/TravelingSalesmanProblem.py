class TravelingSalesmanProblem:
    def __init__(self, costMatrix):
        self.costMatrix = costMatrix
        self.vertexCount = len(costMatrix)
        self.memory = [{} for i in range(self.vertexCount)]
        self.path = [{} for i in range(self.vertexCount)]
        self.initialVertex = -1

    def run(self, initialVertex):
        self.initialVertex = initialVertex
        setNumber = 2**self.vertexCount - 1
        cost = self.__run(initialVertex, self.getSetNumberWithOutVertex(setNumber,initialVertex))
        pathList = self.createPathList(initialVertex, self.getSetNumberWithOutVertex(setNumber,initialVertex))
        return (cost, pathList)

    def generateVerticesFromSetNumber(self,setNumber):
        for vertexNumber in range(self.vertexCount):
            n = setNumber & 1  # Obtengo el bit
            if n == 1:
                yield vertexNumber
            setNumber = setNumber >> 1  # setNumber //= 2


    def __run(self, vertex, setNumber):
        if setNumber == 0:
            return self.costMatrix[vertex][self.initialVertex]
        elif setNumber in self.memory[vertex]:
            return self.memory[vertex][setNumber]

        minCost = -1
        vertexMin = -1

        for u in self.generateVerticesFromSetNumber(setNumber):
            result = self.costMatrix[vertex][u] + self.__run(u, self.getSetNumberWithOutVertex(setNumber, u))
            if minCost == -1 or result < minCost:
                minCost = result
                vertexMin = u

        self.memory[vertex][setNumber] = minCost
        self.path[vertex][setNumber] = vertexMin
        return minCost

    def getSetNumberWithOutVertex(self, setNumber, vertexNumber):
        return setNumber - 2**vertexNumber

    def getSetNumberWithVertex(self,setNumber, vertexNumber):
        return setNumber + 2**vertexNumber

    def createPathList(self, initialVertex,setNumber):
        pathList = [initialVertex]
        actualVertex = initialVertex
        for i in range(self.vertexCount-1):
            nextVertex = self.path[actualVertex][setNumber]
            pathList.append(nextVertex)
            setNumber = self.getSetNumberWithOutVertex(setNumber, nextVertex)
            actualVertex = nextVertex

        pathList.append(initialVertex)
        return pathList
    



