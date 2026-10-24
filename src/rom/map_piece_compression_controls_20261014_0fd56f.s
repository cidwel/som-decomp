.setcpu "65816"
.segment "CODE"
.org $D56F
map_control_0fd56f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
