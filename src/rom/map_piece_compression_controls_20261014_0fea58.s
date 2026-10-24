.setcpu "65816"
.segment "CODE"
.org $EA58
map_control_0fea58:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
