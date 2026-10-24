.setcpu "65816"
.segment "CODE"
.org $E010
boss_selection_zero_direction_actions:
    .word $D0B6 ; selector 0
    .word $D0B6 ; selector 1
    .word $D0B4 ; selector 2
    .word $D0B8 ; selector 3
    .word $D0B8 ; selector 4
    .word $D0B4 ; selector 5
    .word $D0B4 ; selector 6
    .word $D0B4 ; selector 7
