from TSP.TSPIterative import TSPIterative

def main():
    """
    tsp = TSPRecursive([[0,5,6],[6,0,6],[4,6,0]])
    result = tsp.run(0)
    print(result)
    """
    tsp = TSPIterative([[0,5,6],[6,0,6],[4,6,0]])
    print(tsp.run(0))

    return 0


if __name__ == '__main__':
    main()
