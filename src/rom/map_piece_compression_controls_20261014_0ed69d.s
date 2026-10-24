.setcpu "65816"
.segment "CODE"
.org $D69D
map_control_0ed69d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
