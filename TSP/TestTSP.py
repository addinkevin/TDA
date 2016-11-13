import unittest
from TSP.ParserTSPFile import ParserTSPFile
from TSP.TSPIterative import TSPIterative
from TSP.TSPRecursive import TSPRecursive


class TestTSP(unittest.TestCase):
    def _calculateCost(self, matrixCost, list):
        cost = 0
        for i in range(len(list)-1):
            x = list[i]
            y = list[i+1]
            cost += matrixCost[x][y]

        return cost

    def runExample(self, matrixFileName, solutionFileName):
        parser = ParserTSPFile(matrixFileName, solutionFileName)
        matrix = parser.getMatrix()
        expectedList = parser.getSolutionList()
        expectedCost = self._calculateCost(matrix,expectedList)

        tsp = TSPRecursive(matrix)
        #tsp = TSPIterative(matrix)

        actualCost, actualList = tsp.run(0)

        self.assertEqual(expectedCost, actualCost, "No coincidio el costo calculado")
        equalList = expectedList == actualList
        actualList.reverse()
        equalList = equalList or (expectedList == actualList)
        self.assertTrue(equalList, "No hubo coincidencia en los resultados en:" + matrixFileName)



    def testExamples(self):
        self.runExample("./files/tsp1.txt", "./files/tsp1_s.txt")
        #self.runExample("./TSP/files/tsp2.txt", "./TSP/files/tsp2_s.txt")
        #self.runExample("./TSP/files/tsp3.txt", "./TSP/files/tsp3_s.txt")


if __name__ == '__main__':
    unittest.main()
