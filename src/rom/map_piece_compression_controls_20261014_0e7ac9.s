.setcpu "65816"
.segment "CODE"
.org $7AC9
map_control_0e7ac9:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
