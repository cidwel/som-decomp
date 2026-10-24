.setcpu "65816"
.segment "CODE"
.org $C5E7
map_control_0ec5e7:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
