.setcpu "65816"
.segment "CODE"
.org $3FA9
map_control_0c3fa9:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
