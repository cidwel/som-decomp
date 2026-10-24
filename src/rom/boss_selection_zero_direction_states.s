.setcpu "65816"
.segment "CODE"
.org $E000
boss_selection_zero_direction_states:
    .word $D0A2 ; selector 0
    .word $D0A2 ; selector 1
    .word $D0A4 ; selector 2
    .word $D0A0 ; selector 3
    .word $D0A0 ; selector 4
    .word $D0AC ; selector 5
    .word $D0A6 ; selector 6
    .word $D0B0 ; selector 7
