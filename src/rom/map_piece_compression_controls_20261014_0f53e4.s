.setcpu "65816"
.segment "CODE"
.org $53E4
map_control_0f53e4:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
