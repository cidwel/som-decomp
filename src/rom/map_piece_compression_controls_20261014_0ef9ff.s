.setcpu "65816"
.segment "CODE"
.org $F9FF
map_control_0ef9ff:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
