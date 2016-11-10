from TravelingSalesmanProblem import TravelingSalesmanProblem

def main():
    tsp = TravelingSalesmanProblem([[0,5,6],[6,0,6],[4,6,0]])
    result = tsp.run(0)
    print(result)

    return 0


if __name__ == '__main__':
    main()
