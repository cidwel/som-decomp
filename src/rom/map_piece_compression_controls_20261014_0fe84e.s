.setcpu "65816"
.segment "CODE"
.org $E84E
map_control_0fe84e:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
