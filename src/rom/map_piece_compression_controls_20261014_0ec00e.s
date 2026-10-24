.setcpu "65816"
.segment "CODE"
.org $C00E
map_control_0ec00e:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
