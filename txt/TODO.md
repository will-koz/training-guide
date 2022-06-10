# TODO

In addition to using `grep -r TODO`:

- [x] Get input from command line for week and day, and turn it into *exact day*
- [x] Look up *exact day* in example week table
  - [x] If it's an odd week, use Example 1, if it's an even week, use Example 2
  - [x] If it's an odd week (greater than 26), use Example 3, if it's an even week, use Example 4
- [ ] For each of the *workouts*, print out data for that *exercise*
  - [x] For P/S/P workouts, have a custom floating point number that represents structure
    - For example, 0 is the easiest recommended workout, 1 is the hardest recommended workout
  - [ ] Complete this list of workouts:
    - [x] CROSS_TRAIN
    - [ ] LIFT
    - [x] PSP
    - [x] Repetitions
    - [x] RUN_LI
    - [x] RUN_LSD
    - [x] RUN_SI
    - [x] SWIM_LI
    - [x] SWIM_LSD
    - [x] SWIM_SI
    - [x] Warm ups / Active Recovery / Cool down
- [x] Format options
  - [x] Colored / Styled (`--color`, `--no-color`)
  - [x] Checklist (`--list`)
- [ ] User Experience
  - [ ] README
    - [x] Add information about license
    - [ ] General reorganization
    - [ ] Information about what this is / what this isn't, how to use the guide
  - [x] `--help` option
  - [ ] output recommendations from the web page? (`--guide`)
