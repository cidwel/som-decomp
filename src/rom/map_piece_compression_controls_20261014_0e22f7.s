.setcpu "65816"
.segment "CODE"
.org $22F7
map_control_0e22f7:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
