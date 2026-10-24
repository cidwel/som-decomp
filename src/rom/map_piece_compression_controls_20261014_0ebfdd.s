.setcpu "65816"
.segment "CODE"
.org $BFDD
map_control_0ebfdd:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
