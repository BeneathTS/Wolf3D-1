---
# Project for school_21.
## Wolf3D.
---
##### Partial implementation of the engine "Wolfenstein 3D engine" and its improvement using a cross-platform library for working with multimedia "SDL2".
![Example](https://github.com/EmbodimentEvil/Wolf3D-1/blob/master/images/main_menu.png)
---
## Compiling snd running
Runs on OSX.  
Clone `git clone --recursive`  
Run `make` and programm will compile.  
Run it with `./wolf3d`

## Controls
`ESC` - Return to menu. If you on menu - close the program.  
`W`/`A`/`S`/`D` - Movement in space.  
`RIGHT` - Camera rotation to the right.  
`LEFT` - Camera rotation to the left.  
`UP` - Camera rotation to the up.  
`DOWN` - Camera rotation to the down.  
`SPACE`/`MOUSE LEFT` - Shot.  
`MOUSE UP`/`MOUSE DOWN` - Camera rotation to the up/down.  


## Map file format

```
A A A A
A 0 C A
A 0 0 A
A A A A
```
`0`         -	**void, wall/flr cast ignore it, physic ignore it**.  
`:` - `U`	-	**use only 58-85 symbols on ascii (: -> U)**.
`\t`		-	**use tab for split symbols**.

##Authors

**Me**
[**Valera**](https://github.com/BeneathTS)

![Example](https://github.com/EmbodimentEvil/Wolf3D-1/blob/master/images/blue_map.png)
![Example](https://github.com/EmbodimentEvil/Wolf3D-1/blob/master/images/red_map.png)
