.setcpu "65816"
.segment "CODE"
.org $F015
map_control_0ff015:
    .byte $F1 ; progressive-copy count
