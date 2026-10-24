.setcpu "65816"
.segment "CODE"
.org $F81E
map_control_0ef81e:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
