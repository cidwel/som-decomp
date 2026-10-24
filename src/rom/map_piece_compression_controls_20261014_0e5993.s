.setcpu "65816"
.segment "CODE"
.org $5993
map_control_0e5993:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
