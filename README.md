Waterfall Terminal

Goal: Have a Visual Enhanced Terminal with lots of friendly tooling for any new terminal using user. As well as tools that the average Terminal user wishes they had.  
Language: C++  
Libraries: Qt (handles animations and other Gui elements)   


Features:

[ ] Modular Input Output boxes: Sets up the input lines and output lines seperated so its more easily to see what is what.   
[ ] Collapsable Output: be able to minimize Output block attached to the input block. have a button and quick hotkey to hide and unhide the output block.   
[ ] remove old input lines: a button that can be to the left side of the line with the minimize button to close out that input line. (crontrol Z brings it back).  
[ ] be able to click anywhere in the input line with the cursor.  
[ ] Terminal saves off input "history" to a log file with an ID for output which is also saved to a seperate file with that accompanying id. user can set storage limits to these files in case they get to large.   
[ ] Alias Config file native to the terminal that you can save in the top right saving it to a location in application and can copy from to use in other terminals.   
[ ] Depending on size of screen and if enabled from view section of terminal there can be a top file explore bar that mimics normal files explore stuff seperated from the terminal bar at the bottom. navigating in and out via the terminal or the file explore part will cd accompanying location on the other.   
[ ] Support custom fonts.   
[ ] able to have custom text animations.  








Helpers:

Compiling godot:

scons platform=linuxbsd target=editor -j$(nproc)

[text](godot/modules/terminal) [text](godot/modules/terminal/__pycache__) [text](godot/modules/terminal/config.py) [text](godot/modules/terminal/register_types.cpp) [text](godot/modules/terminal/register_types.h) [text](godot/modules/terminal/SCsub) [text](godot/modules/terminal/terminal.cpp) [text](godot/modules/terminal/terminal.h)