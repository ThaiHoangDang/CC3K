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

### Story
- Reach stair
### Heroes 🐈
At the beginning of the game, user can choose between five different heroes

| Hero          | HP  | Atk | Def | Ability |
| ------------- | --- | --- | --- | ------- |
| Shade         | 125 |  25 |  25 | Double the score at the end of game |
| Drow          | 150 |  25 |  15 | <li>x1.5 effect of potions</li><li>Elf can only attack once every turn</li> |
| Vampire       |  50 |  25 |  25 | <li>No maximum HP</li><li>Gains 5 HP every successful attack</li><li>Lose 5 HP instead of attack Dwarf</li> |
| Troll         | 120 |  25 |  15 | Regains 5 HP every turn |
| Goblin        | 110 |  15 |  20 | <li>steals 5 gold from every slain enemy</li><li>Orcs does 50% more damage to Goblin</li> |

Max HP for all races is the starting HP, except for vampires that have no maximum. In our game board, the player character is always denoted by the `@` symbol.

### Control 🕹
The following commands can be supplied to your command interpreter:
- `no`, `so`, `ea`, `we`, `ne`, `nw`, `se`, `sw`: moves the player character one block in the appropriate cardinal direction.
- `u`  + *direction*: uses the potion indicated by the direction (e.g. no, so, ea).
- `a` + *direction*: attacks the enemy in the specified direction (only if the monster is in one block north of the @).
- `f`: stops enemies from moving until this key is pressed again.
- `r`: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
- `q`: allows the player to admit defeat and exit the game.

### Enemies 😈
In a traditional rogue-like game, the enemy character would
have some degree of artificial intelligence. However, for simplicity in CC3k, enemies, except for dragons, move one square
randomly within the confines of the chamber they were spawned in, while Dragons are stationary and always guard a treasure hoard.


| Enemy         | HP  | Atk | Def | Ability |
| ------------- | --- | --- | --- | ------- |
| Human         | 140 |  20 |  20 | Drops two normal piles of gold |
| Dwarf         | 100 |  20 |  30 | Vampires are allergic to dwarves and lose 5 HP rather than gain |
| Elf           | 140 |  30 |  10 | Gets two attacks against every race except drow |
| Orcs          | 180 |  30 |  25 | Does 50% more damage to goblins |
| Merchant      |  30 |  70 |   5 | Steals 5 gold from every slain enemy |
| Dragon        | 150 |  20 |  20 | Always guards a treasure hoard |
| Halfling      | 100 |  15 |  20 | Has a 50% chance to cause the player character to miss in combat |


By default, `Merchants` are neutral to all parties. However, `Merchants` can be attacked and slain by the player character. Attacking or slaying a `Merchant` causes every `Merchant` from that point forward to become hostile to the player character (and will attack them if they pass within a `one block radius`).

Upon their demise, any enemy that is not a `Dragon`, `Human`, or `Merchant` will drop either a small pile or normal pile of gold.

Enemies are denoted on the map as follows: (`H`)uman, d(`W`)arf, (`E`)lf, (`O`)rc, (`M`)erchant, (`D`)ragon, and Half(`L`)ing.

### Potions 🧪
Potions are of two types: `positive` and `negative`. Regardless of the potion itself, all potions are denoted on the map with a `P` symbol. Accordingly, a potion cannot be used unless a player is standing within a `one block radius` of it.

The effects of a particular potion **are not known until it is used for the first time**. In other words, hero will only learn about the effects of that particular potion after using it, while other potions will **NOT** have their effects revealed.

>Positive Potions:
>- Restore health (`RH`): restore up to 10 HP (cannot exceed maximum prescribed by race)
>- Boost Atk (`BA`): increase ATK by 5
>- Boost Def (`BD`): increase Def by 5

>Negative Potions:
>- Poison health (`PH`): lose up to 10 HP (cannot fall below 0 HP)
>- Wound Atk (`WA`): decrease Atk by 5
>- Wound Def (`WD`): decrease Def by 5

The effects of `RH` and `PH` are permanent while the effects of all other potions are limited to the floor they are used on. For example, using a `BA` potion will only boost the player character’s `Atk` until the beginning of the next floor. Note that the PC’s `Atk` and `Def` can never drop below 0.
### Treasure 💰
Treasure in CC3k consists only of `gold`. Gold can be in different types: 

| Name         | Value   |
| ------------ | ------: |
| Small Gold   | 1       |
| Normal Gold  | 2       |
| Dragon Hoard | 6       |

Recall, a `Dragon` must always protect a `Dragon Hoard` whenever it randomly spawns. A `Dragon Hoard` can only be picked up once the `Dragon` guarding it has been slain. Gold, regardless of type, is denoted by `G` on the map.

### Combat
By default, all enemies except for `Merchants` and `Dragons` are hostile to the player character. If the player character enters within a 1 block radius of any hostile enemy, they will attempt to attack the player character (even before the player character has had a chance to attack). If the player character is not within a 1 block radius of the enemy then it will resume random movement.

`Dragons` are considered hostile when the player is next to its `Dragon hoard` or itself, and will use their fire breath to defend its hoard. This means that a `Dragon` might attack even if the player is not next to the `Dragon`, but because it is next to a `Dragon hoard`. Recall that `Merchants` can become hostile when one is attacked/slain by the player character.

Combat is resolved as follows: `Enemies` will auto-attack players given the previously specified criteria, however, there is a `50%` chance their attack misses. The player character has the option of attacking any of the 8 squares adjacent to them and within a 1 block radius. The `PC` never misses. Recall, that the `PC` has initiative and always attacks first.

`Damage` is calculated as follows: 

>`Damage(Defender) = ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))`

where Attacker specifies the attacking character (enemy or PC) and defender specifies the character being attacked. Thus, in a single round a character can be both an attacker and a defender.

### Game Execution 🏃
Follow <a href="#Installation">Installation</a> to download and setup the game if you have not done so. After that, `cd` to `CC3k/src` and the game can be executed in the following ways:
#### Default
```
./cc3k
```
Default map layout with 5 floors, each floor has 5 chambers, and random objects generation.

#### Seed Specified
```
./cc3k -s [seed]
```
Default map layout with 5 floors, each floor has 5 chambers, objects are generated based on provided seed!

Example:
```
./cc3k -s 123
```
#### Map Specified
```
./cc3k [map]
```
If provided file only has map layout but no objects like `hero`/`enemies`/`potions`/`treasure`/`stair`, the program will generate random objects for you. You can try this out by running:
```
./cc3k mapWithNoObjects.txt
```

If provided file has both map layout and objects layout: The program will generate map and objects based on provided file, this ensures that there will be no random objects generation. You can try this out by running:
```
./cc3k mapWithObjects.txt
```
#### Game Mode Specified
```
./cc3k -m [mode]
```
For now, CC3k only has `normal` and `hard` game modes. While `normal` mode is applied by default, `hard` mode needs to be specified when running the game. You can read more about hard mode <a href="#Hard Mode">here</a>.
```
./cc3k -m hard
```
#### Combination
```
./cc3k
```
### Game End 🏁
A game session ends in one of the following ways: 
- the player character **reaches the last stair**
- the player character’s **health reaches 0**
- the player **restarts the game or quits**

A player’s score is only generated in the first two cases. `Score` is determined by the **amount of gold** they have collected in their current character’s life time.

### Display ©
The followings are all symbols used in the game

| Symbol    | Meaning    | Type   | Color | Note    |
| ----------| ---------- | ------ | :---: | ------- |
| `@`       | `Shade`/`Drow`/`Vampire`/`Troll`/`Goblin` | Hero   | 🟦 |
| `H`       | `Human`    | Enemy  | 🟥    |
| `W`       | `Dwarf`    | Enemy  | 🟥    |
| `E`       | `Elf`      | Enemy  | 🟥    |
| `O`       | `Orc`      | Enemy  | 🟥    |
| `M`       | `Merchant` | Enemy  | 🟥    |
| `D`       | `Dragon`   | Enemy  | 🟥    |
| `L`       | `Halfling` | Enemy  | 🟥    |
| `P`       | `RH`/`BA`/`BD`/`PH`/`WA`/`WD` | Potion | 🟩 | Can be used by walking on |
| `G`       | `Small Gold`/`Normal Gold`/`Dragon Hoard` | Treasure | 🟨 | Can be picked up by walking on |
| `/`       | `Stair`    | Object | 🟦    | Takes Hero to new floor |
| `-` and `\|` | `Wall`  | Map    | ⬜️    | Not walkable on |
| `+`       | `Doorway`  | Map    | ⬜️    |
| `#`       | `Passage`  | Map    | ⬜️    |
| `.`       | `Floor tile` | Map   | ⬜️    |

## Features

### Beautiful UI ✨
### Create your own maps! 🗺
### Seeds Support 🌱
When there is no seed specified when running the game, a random seed for that game will be generated and stored in `CC3k/data/seeds.txt`, user can later copy the seed use it to re-play a again.

### Hard Mode 💀
## Installation
Open either `Terminal` if you are using MacOS/Linux or `Command Prompt` if you are a Window user.

Make sure you have a C++ compiler by running `g++ --version`. If not, use chat GPT to look up how to download `g++` for Mac/Win/Linux with version `>= 11` (I did so too, it won't take much time!)

`cd` to the your desired directory and clone the repository by running
```
git clone https://github.com/ThaiHoangDang/CC3K.git
```
After that, `cd` to `CC3k/src`. For example, if you use `Mac` and download the game in `Downloads` folder, run `cd ~/Downloads/CC3k/src`. On the other hand, if you use `Window` and download the game to `Downloads` folder, run `cd %userprofile%\Downloads\CC3k\src`

Run `make` to compile the game (**You only need to do this once, if you have done this before, no need to do this again**). 

Your game is now ready to be played!

## Releases
> **Version 1.0.0** (released Aug 2, 2023)
> * [Document](/src/design.pdf) 
> * [UML](/src/uml.pdf)

> Future Plan
> * There will be a few default maps when running ./cc3k instead of one like right now
> * More game modes
> * Random map generation :D OMG SUPER HARD!
## License
- [MIT License](LICENSE)
---
