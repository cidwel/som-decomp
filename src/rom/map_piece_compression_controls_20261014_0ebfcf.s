.setcpu "65816"
.segment "CODE"
.org $BFCF
map_control_0ebfcf:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
