.setcpu "65816"
.segment "CODE"
.org $033F
map_control_0e033f:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
