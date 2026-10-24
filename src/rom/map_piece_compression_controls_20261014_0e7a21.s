.setcpu "65816"
.segment "CODE"
.org $7A21
map_control_0e7a21:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
