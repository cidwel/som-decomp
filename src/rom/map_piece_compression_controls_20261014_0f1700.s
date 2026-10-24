.setcpu "65816"
.segment "CODE"
.org $1700
map_control_0f1700:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
