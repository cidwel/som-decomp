.setcpu "65816"
.segment "CODE"
.org $DADE
boss_selection_fourteen_phase_one_random_states:
    .word $D90D ; selector 0
    .word $D90F ; selector 1
    .word $D911 ; selector 2
    .word $D911 ; selector 3
