.setcpu "65816"
.segment "CODE"
.org $353D
map_control_0d353d:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
