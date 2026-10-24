.setcpu "65816"
.segment "CODE"
.org $CEC1
map_control_0ecec1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
