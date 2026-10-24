.setcpu "65816"
.segment "CODE"
.org $9C68
map_control_0e9c68:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
