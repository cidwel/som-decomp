.setcpu "65816"
.segment "CODE"
.org $BFBC
map_control_0ebfbc:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
