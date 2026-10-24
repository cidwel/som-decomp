.setcpu "65816"
.segment "CODE"
.org $3170
map_control_0d3170:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
