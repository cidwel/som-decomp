.setcpu "65816"
.segment "CODE"
.org $BFA9
map_control_0ebfa9:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
