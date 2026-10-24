.setcpu "65816"
.segment "CODE"
.org $108D
map_control_0d108d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
