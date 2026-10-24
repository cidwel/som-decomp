.setcpu "65816"
.segment "CODE"
.org $763E
map_control_0e763e:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
