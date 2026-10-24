.setcpu "65816"
.segment "CODE"
.org $427D
map_control_0c427d:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
