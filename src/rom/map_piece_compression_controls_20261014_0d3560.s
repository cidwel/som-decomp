.setcpu "65816"
.segment "CODE"
.org $3560
map_control_0d3560:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
