.setcpu "65816"
.segment "CODE"
.org $EE3F
map_control_0eee3f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
