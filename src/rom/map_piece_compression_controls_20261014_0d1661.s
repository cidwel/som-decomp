.setcpu "65816"
.segment "CODE"
.org $1661
map_control_0d1661:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
