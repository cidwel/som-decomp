.setcpu "65816"
.segment "CODE"
.org $3E75
map_control_0d3e75:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
