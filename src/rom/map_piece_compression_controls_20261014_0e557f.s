.setcpu "65816"
.segment "CODE"
.org $557F
map_control_0e557f:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
