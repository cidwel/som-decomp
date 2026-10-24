.setcpu "65816"
.segment "CODE"
.org $BF45
map_control_0ebf45:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
