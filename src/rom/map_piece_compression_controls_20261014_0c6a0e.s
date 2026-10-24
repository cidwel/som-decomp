.setcpu "65816"
.segment "CODE"
.org $6A0E
map_control_0c6a0e:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
