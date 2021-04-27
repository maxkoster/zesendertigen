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

while dice > 0:
    throw = random.sample(range(1,7),dice)
    actions = getActions(throw)
    value = [sum(i) for i in actions]
    states = [i for i in zip(value,[len(j) for j in actions])]
    
    choice = random.randint(0,len(actions)-1)
    total += value[choice]
    dice -= len(actions[choice])

print(total)
print(reward(total))