.setcpu "65816"
.segment "CODE"
.org $4C4E
map_control_0d4c4e:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
