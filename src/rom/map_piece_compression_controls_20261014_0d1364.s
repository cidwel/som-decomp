.setcpu "65816"
.segment "CODE"
.org $1364
map_control_0d1364:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
