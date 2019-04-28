import numpy as np

tests = int(input())
for _ in range(tests):
    n = int(input())

    stones = np.empty((n, 3))
    for stone in range(n):
        stones[stone] = list(map(int, input().split()))

    energyConsumed = 0

    while len(stones) != 0:

        bestLoss = float("inf")
        bestLoss_idx = -1

        for stone_i, stone in enumerate(stones):
            netloss = 0
            eating_time = stone[0]
            energies = stones[:, 1] - eating_time * stones[:, 2]

            for i in range(len(energies)):
                if i == stone_i:
                    continue
                if energies[i] < 0:
                    netloss += stones[i, 1]
                else:
                    netloss += stones[i, 1] - energies[i]

            if netloss < bestLoss:
                bestLoss = netloss
                bestLoss_idx = stone_i
            elif netloss == bestLoss:
                if stones[bestLoss_idx, 1] < stones[stone_i, 1]:
                    bestLoss = netloss
                    bestLoss_idx = stone_i

        energyConsumed += stones[bestLoss_idx, 1]

        energies = stones[:, 1] - stones[bestLoss_idx, 0] * stones[:, 2]

        dead_rocks = [bestLoss_idx]
        for i in range(len(energies)):
            if energies[i] < 0:
                dead_rocks.append(i)

        stones[:, 1] = energies

        stones = np.delete(stones, dead_rocks, axis=0)

    print("Case #{}: {}".format(_+1, int(energyConsumed)))
