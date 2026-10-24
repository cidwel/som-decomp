.setcpu "65816"
.segment "CODE"
.org $C9C6
map_control_0dc9c6:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
