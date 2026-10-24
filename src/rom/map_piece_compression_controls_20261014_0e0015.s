.setcpu "65816"
.segment "CODE"
.org $0015
map_control_0e0015:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
