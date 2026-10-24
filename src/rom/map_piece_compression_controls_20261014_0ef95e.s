.setcpu "65816"
.segment "CODE"
.org $F95E
map_control_0ef95e:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
