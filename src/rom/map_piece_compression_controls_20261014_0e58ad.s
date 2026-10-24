.setcpu "65816"
.segment "CODE"
.org $58AD
map_control_0e58ad:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
