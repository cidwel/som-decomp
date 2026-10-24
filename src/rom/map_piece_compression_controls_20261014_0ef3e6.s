.setcpu "65816"
.segment "CODE"
.org $F3E6
map_control_0ef3e6:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
