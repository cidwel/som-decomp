.setcpu "65816"
.segment "CODE"
.org $3997
map_control_0d3997:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
