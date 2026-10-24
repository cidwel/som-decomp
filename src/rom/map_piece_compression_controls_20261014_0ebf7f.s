.setcpu "65816"
.segment "CODE"
.org $BF7F
map_control_0ebf7f:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
