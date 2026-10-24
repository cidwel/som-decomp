.setcpu "65816"
.segment "CODE"
.org $271E
map_control_0d271e:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
