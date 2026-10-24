.setcpu "65816"
.segment "CODE"
.org $1686
map_control_0d1686:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
