.setcpu "65816"
.segment "CODE"
.org $8A6E
map_control_0d8a6e:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
