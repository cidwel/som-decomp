.setcpu "65816"
.segment "CODE"
.org $3A11
map_control_0d3a11:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
