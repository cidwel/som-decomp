.setcpu "65816"
.segment "CODE"
.org $3FD6
map_control_0d3fd6:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
