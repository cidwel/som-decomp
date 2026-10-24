.setcpu "65816"
.segment "CODE"
.org $7D22
map_control_0c7d22:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
