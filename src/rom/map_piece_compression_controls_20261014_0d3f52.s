.setcpu "65816"
.segment "CODE"
.org $3F52
map_control_0d3f52:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
