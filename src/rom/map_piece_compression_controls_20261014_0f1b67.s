.setcpu "65816"
.segment "CODE"
.org $1B67
map_control_0f1b67:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
