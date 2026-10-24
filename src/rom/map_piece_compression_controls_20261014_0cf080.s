.setcpu "65816"
.segment "CODE"
.org $F080
map_control_0cf080:
    .byte $F1 ; progressive-copy count
