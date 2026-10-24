.setcpu "65816"
.segment "CODE"
.org $7FF9
map_control_0d7ff9:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
