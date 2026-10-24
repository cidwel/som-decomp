.setcpu "65816"
.segment "CODE"
.org $1CB0
map_control_0d1cb0:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
