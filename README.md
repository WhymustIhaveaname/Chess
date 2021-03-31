# Chess
Chess using alpha-beta pruning

### Usage

Run `./a.out`, input algebraic notation to move, input `h` for AI's help.

On my i7-1165G7 CPU's single core, it normally can `searched 21924658 cases in 12882.108 ms at deep 7, avg 0.588 us/case`.

### File Structure
* a.out            : runable file compiled two years ago;
* top_layer.c      : where main lays;
* interface.c      : human interface;
* chess.c          : core algorithm;
* bell.py          : call by top_layer.c to play an alert sound;
* chess.py         : I forget what it is.
