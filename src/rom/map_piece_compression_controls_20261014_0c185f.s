.setcpu "65816"
.segment "CODE"
.org $185F
map_control_0c185f:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
