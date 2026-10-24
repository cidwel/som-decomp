.setcpu "65816"
.segment "CODE"
.org $DADA
boss_selection_fourteen_target_random_actions:
    .word $D902 ; selector 0
    .word $D904 ; selector 1
