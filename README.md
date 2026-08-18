# Colonia

A simulation of ant colony foraging behavior, built from scratch in C.

The goal is to study how simple, local ant behavior — random search, direct
perception of nearby food, and a decaying pheromone trail — produces
colony-level coordination (efficient nest-to-food routing) without any ant
having global knowledge of the world. This is the concept of stigmergy:
agents communicating indirectly by modifying a shared environment.

The project also compares the detailed spatial simulation against a reduced
statistical (Markov chain) model of the same system, run on a discrete-event
simulation engine, to see how well the simplified model predicts the
detailed one.

## Structure

- `engine/` — a small simulation engine with two independent drivers: a
  discrete-event kernel for sparse/event-based models, and a fixed-timestep
  kernel for dense, continuously-updating models. Shared math (RNG,
  distributions) and statistics utilities live here too.
- `models/mm1/` — a classic M/M/1 queue, built on the discrete-event kernel.
- `models/ant/` — the ant colony simulation: world, agents, pheromone field,
  behavior, statistics, and an SDL2 viewer.
