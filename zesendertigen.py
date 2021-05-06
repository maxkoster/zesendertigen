#! /usr/bin/env python3

import numpy as np
import itertools
import random

def getActions(throw):
    actions = []
    for dice in range(1,len(throw)+1):
        for t in itertools.combinations(throw,dice):
            actions.append(t)
    return list(set(actions))

def reward(total):
    if total > 10:
        return total-30
    if total <= 10:
        return 10*(10-total)

dice = 6
total = 0

tries = 100000
avg = 0
for j in range(tries):
	print(j)
	while dice > 0:
		throw = random.sample(range(1,7),dice)
		actions = getActions(throw)
		value = [sum(i) for i in actions]
		states = [i for i in zip(value,[len(j) for j in actions])]
		choice = np.argmax([i[0]/i[1] for i in states]) 
		total += value[choice]
		dice -= len(actions[choice])
	avg += total

avg = avg/tries

print(avg)
print(reward(avg))
