.setcpu "65816"
.segment "CODE"
.org $3130
map_control_0e3130:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
