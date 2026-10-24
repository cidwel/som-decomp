.setcpu "65816"
.segment "CODE"
.org $3F99
map_control_0d3f99:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
