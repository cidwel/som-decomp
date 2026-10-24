.setcpu "65816"
.segment "CODE"
.org $295F
map_control_0e295f:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
