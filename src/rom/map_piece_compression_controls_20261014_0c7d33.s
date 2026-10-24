.setcpu "65816"
.segment "CODE"
.org $7D33
map_control_0c7d33:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
