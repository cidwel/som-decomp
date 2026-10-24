.setcpu "65816"
.segment "CODE"
.org $2007
map_control_0d2007:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
