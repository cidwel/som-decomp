.setcpu "65816"
.segment "CODE"
.org $1088
map_control_0c1088:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
