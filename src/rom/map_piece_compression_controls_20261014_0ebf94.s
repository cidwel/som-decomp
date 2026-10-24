.setcpu "65816"
.segment "CODE"
.org $BF94
map_control_0ebf94:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
