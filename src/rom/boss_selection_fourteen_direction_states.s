.setcpu "65816"
.segment "CODE"
.org $DAD2
boss_selection_fourteen_direction_states:
    .word $D8FE ; selector 0
    .word $D8F8 ; selector 1
    .word $D8FC ; selector 2
    .word $D8FA ; selector 3
