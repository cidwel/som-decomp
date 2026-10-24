.setcpu "65816"
.segment "CODE"
.org $1876
map_control_0d1876:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
