.setcpu "65816"
.segment "CODE"
.org $BFEB
map_control_0ebfeb:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
