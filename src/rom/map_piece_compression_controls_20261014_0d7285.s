.setcpu "65816"
.segment "CODE"
.org $7285
map_control_0d7285:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
