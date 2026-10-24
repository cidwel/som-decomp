.setcpu "65816"
.segment "CODE"
.org $E130
map_control_0de130:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
