.setcpu "65816"
.segment "CODE"
.org $3178
map_control_0d3178:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
