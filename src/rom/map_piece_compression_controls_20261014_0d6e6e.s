.setcpu "65816"
.segment "CODE"
.org $6E6E
map_control_0d6e6e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
