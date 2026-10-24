.setcpu "65816"
.segment "CODE"
.org $9E07
map_control_0e9e07:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
