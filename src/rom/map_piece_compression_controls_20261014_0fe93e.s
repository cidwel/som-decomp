.setcpu "65816"
.segment "CODE"
.org $E93E
map_control_0fe93e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
