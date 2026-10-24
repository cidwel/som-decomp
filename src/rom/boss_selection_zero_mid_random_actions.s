.setcpu "65816"
.segment "CODE"
.org $E024
boss_selection_zero_mid_random_actions:
    .word $D0C3 ; selector 0
    .word $D0C3 ; selector 1
