.setcpu "65816"
.segment "CODE"
.org $9E1D
map_control_0d9e1d:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
