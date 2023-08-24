<h1 align="center">
    <br>
    <img src="/src/data/logo.png" alt="CC3k" width="200"></a>
</h1>

<h4 align="center">ChamberCrawler3000 (CC3k) is a simplified rogue-like game!</h4>

<p align="center">
    <a href="#background">Background</a> •
    <a href="#gameplay">Gameplay</a> •
    <a href="#features">Features</a> •
    <a href="#installation">Installation</a> •
    <a href="#releases">Releases</a> •
    <a href="#license">License</a>
</p>

<p align="center">
  <img src="/src/data/pic1.png" />
</p>

## Background
Hiii 👋🏻,

I'm Hoang, this is a project for a second-year CS course, [CS 246](https://student.cs.uwaterloo.ca/~cs246/S23/index.shtml), at University of Waterloo 🇨🇦. I took this course when I was on exchange, yes, I was an exchange student from Vietnam 🇻🇳.

**CC3k** is my first ever personal project and I have put a lot of effort into it. The project was built on top of `C++` using different `OOP` concepts like `Inheritance`, `Polymorphism`, and `Encapsulation`.

This is a game where we control a hero ⚔️ to explore dungeon with different floors and different chambers. A long the way, there will be many item that we can pick up and use like Gold or Potion. And of course, the most important component of the game is the Enemy 😈 which can come from different kinds with different abilities, who is always ready to fight our hero!

Hope you guys will like it!

Cheers 🤗, <br>
Hoang Dang.

## Gameplay
### Heroes
At the beginning of the game, user can choose between five different heroes

| Hero          | HP  | Atk | Def | Ability |
| ------------- | --- | --- | --- | ------- |
| Shade         | 125 |  25 |  25 | <li>Double the score at the end of game </li> |
| Drow          | 150 |  25 |  15 | <li>x1.5 effect of potions</li><li>Elf can only attack once every turn</li> |
| Vampire       |  50 |  25 |  25 | <li>No maximum HP</li><li>Gains 5 HP every successful attack</li><li>Lose 5 HP instead of attack Dwarf</li> |
| Troll         | 120 |  25 |  15 | <li>Regains 5 HP every turn</li>
| Goblin        | 110 |  15 |  20 | <li>steals 5 gold from every slain enemy</li><li>Orcs does 50% more damage to Goblin</li> |

Max HP for all races is the starting HP, except for vampires that have no maximum. In our game board, the player character is always denoted by the `@` symbol.
### Enemies
In a traditional rogue-like game, the enemy character would
have some degree of artificial intelligence. However, for simplicity in CC3k, enemies, except for dragons, move one square
randomly within the confines of the chamber they were spawned in, while Dragons are stationary and always guard a treasure hoard.


| Enemy         | HP  | Atk | Def | Ability |
| ------------- | --- | --- | --- | ------- |
| Human         | 140 |  20 |  20 | <li>Drops two normal piles of gold </li> |
| Dwarf         | 100 |  20 |  30 | <li>Vampires are allergic to dwarves and lose 5 HP rather than gain </li> |
| Elf           | 140 |  30 |  10 | <li>Gets two attacks against every race except drow</li> |
| Orcs          | 180 |  30 |  25 | <li>Does 50% more damage to goblins</li>
| Merchant      |  30 |  70 |   5 | <li>Steals 5 gold from every slain enemy</li> |
| Dragon        | 150 |  20 |  20 | <li>Always guards a treasure hoard</li> |
| Halfling      | 100 |  15 |  20 | <li>Has a 50% chance to cause the player character to miss in combat</li> |


By default, `merchants` are neutral to all parties. However, merchants can be attacked and slain by the player character. Attacking or slaying a `Merchant` causes every `Merchant` from that point forward to become hostile to the player character (and will attack them if they pass within a `one block radius`).

Upon their demise, any enemy that is not a `Dragon`, `Human`, or `Merchant` will drop either a small pile or normal pile of gold.

Enemies are denoted on the map as follows: (`H`)uman, d(`W`)arf, (`E`)lf, (`O`)rc, (`M`)erchant, (`D`)ragon, Half(`L`)ing.

### Potions

### Treasure

### Control

### Game Flow

## Features

### Beautiful UI
### Create your own maps!
### Seeds Support

## Installation


## Releases
> **Version 1.0.0** (released Aug 2, 2023)
> * [Document](/src/design.pdf) 
> * [UML](/src/uml.pdf)

## License
- [MIT License](LICENSE)
---
