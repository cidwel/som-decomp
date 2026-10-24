.setcpu "65816"
.segment "CODE"
.org $1352
map_control_0d1352:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
