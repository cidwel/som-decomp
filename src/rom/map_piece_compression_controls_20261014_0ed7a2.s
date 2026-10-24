.setcpu "65816"
.segment "CODE"
.org $D7A2
map_control_0ed7a2:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
