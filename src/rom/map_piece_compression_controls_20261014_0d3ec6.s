.setcpu "65816"
.segment "CODE"
.org $3EC6
map_control_0d3ec6:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
