.setcpu "65816"
.segment "CODE"
.org $7EA8
map_control_0c7ea8:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
