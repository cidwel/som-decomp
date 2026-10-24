.setcpu "65816"
.segment "CODE"
.org $3C80
boss_terminal_clear_state_pointers:
    .word $3C84, $3C89
