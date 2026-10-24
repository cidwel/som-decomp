.setcpu "65816"
.segment "CODE"
.org $F9D7
map_control_0ef9d7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
