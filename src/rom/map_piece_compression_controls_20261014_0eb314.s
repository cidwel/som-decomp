.setcpu "65816"
.segment "CODE"
.org $B314
map_control_0eb314:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
