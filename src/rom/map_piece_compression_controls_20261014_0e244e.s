.setcpu "65816"
.segment "CODE"
.org $244E
map_control_0e244e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
