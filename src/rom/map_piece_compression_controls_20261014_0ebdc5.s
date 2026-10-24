.setcpu "65816"
.segment "CODE"
.org $BDC5
map_control_0ebdc5:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
