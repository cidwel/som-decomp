.setcpu "65816"
.segment "CODE"
.org $2018
map_control_0d2018:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
