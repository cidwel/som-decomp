.setcpu "65816"
.segment "CODE"
.org $E37E
boss_selection_thirteen_default_random_actions:
    .word $E34B ; selector 0
    .word $E351 ; selector 1
    .word $E35D ; selector 2
    .word $E365 ; selector 3
