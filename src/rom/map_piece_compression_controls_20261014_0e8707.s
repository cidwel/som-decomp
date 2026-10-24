.setcpu "65816"
.segment "CODE"
.org $8707
map_control_0e8707:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
