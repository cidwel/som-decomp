.setcpu "65816"
.segment "CODE"
.org $5260
map_control_0e5260:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
