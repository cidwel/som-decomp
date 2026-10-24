.setcpu "65816"
.segment "CODE"
.org $7161
map_control_0e7161:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
