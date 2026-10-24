.setcpu "65816"
.segment "CODE"
.org $1001
map_control_0e1001:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
