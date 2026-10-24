.setcpu "65816"
.segment "CODE"
.org $3F72
map_control_0d3f72:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
