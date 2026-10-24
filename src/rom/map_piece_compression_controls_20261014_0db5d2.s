.setcpu "65816"
.segment "CODE"
.org $B5D2
map_control_0db5d2:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
