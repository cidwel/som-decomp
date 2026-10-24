.setcpu "65816"
.segment "CODE"
.org $56B9
map_control_0c56b9:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
