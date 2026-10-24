.setcpu "65816"
.segment "CODE"
.org $E386
boss_selection_thirteen_target_random_actions:
    .word $E34D ; selector 0
    .word $E34F ; selector 1
