.setcpu "65816"
.segment "CODE"
.org $4E40
map_control_0e4e40:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
