.setcpu "65816"
.segment "CODE"
.org $EA0A
map_control_0fea0a:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
