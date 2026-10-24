.setcpu "65816"
.segment "CODE"
.org $1742
map_control_0c1742:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
