.setcpu "65816"
.segment "CODE"
.org $FE3F
map_control_0dfe3f:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
