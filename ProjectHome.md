# Cosmoscroll #

Cosmoscroll is a space-based shoot'em up game. Inspired by games such as R-Type and Gradius, it features side-scrolling, retro-looking graphics and chiptune music.

This project is written in C++ using the SFML library. It also uses DUMB for playing modules files, and TinyXML for parsing XML files.

Cosmoscroll is free software and licensed under GPLv3. See 'AUTHORS' file for more information.


![http://media.indiedb.com/images/games/1/34/33241/screenshot_missile.png](http://media.indiedb.com/images/games/1/34/33241/screenshot_missile.png)

## Features ##

  * Complete 8 challenging levels and beat the final boss. Collect points and unlock upgrades your spaceship in the armory!
  * Infinity Mode: Hold as long as possible against more and more powerful enemy waves. Try to set a new high-score and share it online on the leaderboard!
  * Various enemies, end bosses, weapons and powerups
  * Available in English, French and German


## Bug report and contributing ##

If you found a bug, please report it on the <a href='https://github.com/abodelot/cosmoscroll/issues'>bug tracker</a>.

If you wish to add a new language,  please see the <a href='https://github.com/abodelot/cosmoscroll/wiki/Internationalization'>guide to Internationalization</a>.

## How to compile ##

Cosmoscroll should compile on any system supported by the SFML library. The easiest way to grab the source code is to clone the project's git repository (follow instructions on this page).

You need to install the following libraries:

  * <a href='http://www.sfml-dev.org/download/sfml/2.1/'>SFML 2</a>
  * <a href='http://dumb.sourceforge.net'>DUMB</a> (for Debian-based systems, simply install the package libdumb1-dev)

The repository already contains a Code::Blocks project file (cosmoscroll.cbp). If you want to use another IDE:

  * Make sure your compiler is c++11 compliant
  * Add the `src` directory to your compiler search path
  * Link against the libraries mentioned above

Linux and Mac OS users can also simply use the UNIX makefile.

