.setcpu "65816"
.segment "CODE"
.org $20F2
map_control_0e20f2:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
