.setcpu "65816"
.segment "CODE"
.org $58FC
map_control_0e58fc:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
