.setcpu "65816"
.segment "CODE"
.org $2789
map_control_0d2789:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
