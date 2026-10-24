.setcpu "65816"
.segment "CODE"
.org $C75E
map_control_0ec75e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
