.setcpu "65816"
.segment "CODE"
.org $1927
map_control_0d1927:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
