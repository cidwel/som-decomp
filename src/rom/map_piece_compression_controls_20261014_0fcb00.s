.setcpu "65816"
.segment "CODE"
.org $CB00
map_control_0fcb00:
    .byte $F1 ; progressive-copy count
