.setcpu "65816"
.segment "CODE"
.org $D7BE
map_control_0ed7be:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
