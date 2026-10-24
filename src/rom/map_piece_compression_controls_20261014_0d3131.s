.setcpu "65816"
.segment "CODE"
.org $3131
map_control_0d3131:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
