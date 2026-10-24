.setcpu "65816"
.segment "CODE"
.org $8C2C
map_control_0f8c2c:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
