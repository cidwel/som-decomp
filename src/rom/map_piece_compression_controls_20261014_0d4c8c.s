.setcpu "65816"
.segment "CODE"
.org $4C8C
map_control_0d4c8c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
