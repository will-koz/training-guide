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
    - [ ] RUN_LI
    - [x] RUN_LSD
    - [x] RUN_SI
    - [ ] SWIM_LI
    - [x] SWIM_LSD
    - [ ] SWIM_SI
    - [x] Warm ups / Active Recovery / Cool down
- [ ] Format options
  - [ ] Colored / Styled
  - [ ] Checklist
- [ ] UX
  - [ ] `--help` option
  - [ ] output recommendations from the webpage?
