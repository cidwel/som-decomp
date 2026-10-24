.setcpu "65816"
.segment "CODE"
.org $F8E4
map_control_0cf8e4:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
