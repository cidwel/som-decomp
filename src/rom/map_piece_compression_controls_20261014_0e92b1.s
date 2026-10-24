.setcpu "65816"
.segment "CODE"
.org $92B1
map_control_0e92b1:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
