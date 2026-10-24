.setcpu "65816"
.segment "CODE"
.org $E020
boss_selection_zero_far_random_actions:
    .word $D0C7 ; selector 0
    .word $D0C5 ; selector 1
