.setcpu "65816"
.segment "CODE"
.org $D09F
map_control_0fd09f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
