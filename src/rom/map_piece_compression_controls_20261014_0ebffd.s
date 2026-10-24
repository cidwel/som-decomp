.setcpu "65816"
.segment "CODE"
.org $BFFD
map_control_0ebffd:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
