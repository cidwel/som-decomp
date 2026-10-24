.setcpu "65816"
.segment "CODE"
.org $34C7
map_control_0e34c7:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
