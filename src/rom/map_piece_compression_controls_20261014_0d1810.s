.setcpu "65816"
.segment "CODE"
.org $1810
map_control_0d1810:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
