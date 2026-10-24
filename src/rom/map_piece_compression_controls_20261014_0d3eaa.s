.setcpu "65816"
.segment "CODE"
.org $3EAA
map_control_0d3eaa:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
