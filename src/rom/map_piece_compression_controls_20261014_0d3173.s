.setcpu "65816"
.segment "CODE"
.org $3173
map_control_0d3173:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
