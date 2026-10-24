.setcpu "65816"
.segment "CODE"
.org $9B03
map_control_0d9b03:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
