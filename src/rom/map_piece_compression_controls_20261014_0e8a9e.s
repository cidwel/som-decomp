.setcpu "65816"
.segment "CODE"
.org $8A9E
map_control_0e8a9e:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
