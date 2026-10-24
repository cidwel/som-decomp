.setcpu "65816"
.segment "CODE"
.org $5114
map_control_0d5114:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
