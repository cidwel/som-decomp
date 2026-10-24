.setcpu "65816"
.segment "CODE"
.org $C9E9
map_control_0dc9e9:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
