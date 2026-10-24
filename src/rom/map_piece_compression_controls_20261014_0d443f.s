.setcpu "65816"
.segment "CODE"
.org $443F
map_control_0d443f:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
