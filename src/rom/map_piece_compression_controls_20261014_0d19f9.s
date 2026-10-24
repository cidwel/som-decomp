.setcpu "65816"
.segment "CODE"
.org $19F9
map_control_0d19f9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
