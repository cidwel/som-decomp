.setcpu "65816"
.segment "CODE"
.org $020E
map_control_0e020e:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
