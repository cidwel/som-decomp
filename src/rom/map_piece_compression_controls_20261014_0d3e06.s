.setcpu "65816"
.segment "CODE"
.org $3E06
map_control_0d3e06:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
