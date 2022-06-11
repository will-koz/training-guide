# Training Guide

Found a great training guide from the Navy Seals for training. Most of the guide is just tables that
I thought should be automated to make a seemingly curated viewing experience. The guide can be found
at [SWCC GUIDE](https://www.sealswcc.com/training/navy-seal-swcc-physical-training-guide.html).

**This is not a primary-source workout guide.** All of this data comes from the online training
guide or is a workout that I use in my personal workout. This is not an original workout plan that
is delivered in the form of code.

Editing [custom.c](custom.c) is ~~heavily recommended~~ required because the current values are
tweaked to my workout. For example, I do more push ups and sit ups than is recommended by the guide,
but at the time I found out about the guide, I would have reduced the number of push ups and sit ups
I would have done, if I followed the guide to the letter.

Odd weeks prior to week 26 use Example 1; even weeks prior to week 27 use Example 2; odd weeks after
week 26 use Example 3; and even weeks after week 27 use Example 4.

## Requirements

- C compiler. `gcc` is specified in the [Makefile](Makefile)

## Building

- `make`

After you have read through the values in [custom.c](custom.c) and made sure the values are good for
you,

the guide can be built using the command `make`.

*Side Note:* Cross training is something that could be done everyday, according to the guide, but
should not need to be done twice a day. Reps (i.e. push ups, situps, and pull ups) can be done twice
a day. First, as part of that day's reps, and second as part of that week's reps. Both of these can
be edited in [custom.c](custom.c). If an exercise is optional and not required, it will be gray when
it is outputted if color output is specified.

## Running

- `./guide 1 Sunday`

Currently, the guide is run using `./guide`, **followed by the week and the day**. A valid
utilization of the guide would be `./guide 7 Sunday` for the Sunday of the 7th week of the training.
You can also use characters from `MTWtHFSsU` format, so `./guide 7 U` would give the same output as
`./guide 7 Sunday`.

To get help information or see parts from the guide, use `--help` and `--guide` respectively. You
can use the `--color` and `--no-color` options to specify color, and `--list` to add a checklist
prefix to each line (which could be useful if you print out that day's exercises).

## Using

**This is a reminder to reread through the values that are written in [custom.c](custom.c).** This
is supposed to be a dynamic training guide that is tailored for each person, by that person. If you
decide to use the guide without recompiling, there are three exercises that you might not be
familiar with. Those are:
- *Football suicides* come from the regular tennis suicides, which are small in comparison. On a
tennis court, there are 5 lines. You stand at the first and run to the second, then back to the
first, then to the third, the first, the fourth, the first, the fifth, and finally return to the
first. A football suicide is the same thing, but using the 10 yard lines of a football field. After
each football suicide, 1100 yards will be ran.
- *Stair-laps*. Running up stairs is one of the best exercises for the lower body (citation needed).
At most high schools' football fields, the arena is set up with stairs going up through the
bleachers. One lap would be running up a stairwell, running to the next stairwell and running down
it, running to the next stairwell and running up it and so on. Because there can be a big size
difference between, for example Michigan stadium and the average suburbian high school stadium,
(citation needed) this is another value in [custom.c](custom.c) that should be changed.
- *T-pose flicks* are standing in the T-pose position and flicking your fingers for the amount of
time specified or as long as possible. This is not complex, but if you have weak forearms or
deltoids, it can be very hard to hold for extended periods of time.

![One handed pull-up](images/one-handed-pull-up.png)
![Relevant XKCD](https://imgs.xkcd.com/comics/exercise_progression.png)

## TODO

TODO is kept in [txt/TODO.md](txt/TODO.md).

## License

This project is licensed under the [MIT license](license.txt), except for the data outputted by
`--guide`, which is public domain because it comes from the United States Navy.
