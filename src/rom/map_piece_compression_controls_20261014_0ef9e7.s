.setcpu "65816"
.segment "CODE"
.org $F9E7
map_control_0ef9e7:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
