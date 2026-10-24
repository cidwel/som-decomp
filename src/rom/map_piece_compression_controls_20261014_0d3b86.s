.setcpu "65816"
.segment "CODE"
.org $3B86
map_control_0d3b86:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
