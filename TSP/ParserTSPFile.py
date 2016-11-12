class ParserTSPFile:
    FULL_MATRIX = "FULL_MATRIX"
    LOWER_DIAG_ROW = "LOWER_DIAG_ROW"

    def __init__(self, matrixFileName, solutionFileName):
        self.matrixFileName = matrixFileName
        self.solutionFileName = solutionFileName

    def getMatrix(self):
        file = open(self.matrixFileName)
        line = file.readline().rstrip()
        if (line == ParserTSPFile.FULL_MATRIX):
            matrix = self._getFullMatrix(file)
        else:
            matrix = self._getLowerDiagRowMatrix(file)

        file.close()

        return matrix

    def _getFullMatrix(self,file):
        matrix = []
        for line in file:
            lineSplit = line.split()
            matrix.append([int(x) for x in lineSplit])

        return matrix

    def _getLowerDiagRowMatrix(self,file):
        matrix = [[]]
        actualRow = 0
        actualCol = 0
        rowLengthToRead = 1
        for line in file:
            distance = int(line)
            matrix[actualRow].append(distance)
            if (actualRow != actualCol):
                matrix[actualCol].append(distance)
            actualCol += 1
            if (actualCol >= rowLengthToRead):
                actualCol = 0
                actualRow += 1
                rowLengthToRead += 1
                matrix.append([])

        matrix.pop() # Para borrar la ultima lista vacia agregada.
        return matrix

    def getSolutionList(self):
        file = open(self.solutionFileName)
        list = []
        for line in file:
            vertex = int(line) - 1
            list.append(vertex)
        file.close()
        return list

