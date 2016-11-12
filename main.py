#from TSP.TravelingSalesmanProblem import TravelingSalesmanProblem
#from TSP.ParserTSPFile import ParserTSPFile
import itertools

from TSP.TSP import TSP

def main():
    """
    tsp = TravelingSalesmanProblem([[0,5,6],[6,0,6],[4,6,0]])
    result = tsp.run(0)
    print(result)
    """
    tsp = TSP([[0,5,6],[6,0,6],[4,6,0]])
    print(tsp.run(0))

    return 0


if __name__ == '__main__':
    main()
