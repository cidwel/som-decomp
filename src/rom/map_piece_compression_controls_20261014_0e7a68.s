.setcpu "65816"
.segment "CODE"
.org $7A68
map_control_0e7a68:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
