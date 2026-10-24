.setcpu "65816"
.segment "CODE"
.org $BF6B
map_control_0ebf6b:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
