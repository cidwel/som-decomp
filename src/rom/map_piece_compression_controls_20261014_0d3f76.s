.setcpu "65816"
.segment "CODE"
.org $3F76
map_control_0d3f76:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
