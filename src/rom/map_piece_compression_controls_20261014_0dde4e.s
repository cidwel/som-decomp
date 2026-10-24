.setcpu "65816"
.segment "CODE"
.org $DE4E
map_control_0dde4e:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
