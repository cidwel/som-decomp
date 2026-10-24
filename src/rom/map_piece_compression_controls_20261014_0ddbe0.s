.setcpu "65816"
.segment "CODE"
.org $DBE0
map_control_0ddbe0:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
