.setcpu "65816"
.segment "CODE"
.org $9B3E
map_control_0d9b3e:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
