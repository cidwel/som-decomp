.setcpu "65816"
.segment "CODE"
.org $E7FF
map_control_0fe7ff:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
