.setcpu "65816"
.segment "CODE"
.org $B62B
map_control_0db62b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $F1 ; progressive-copy count
