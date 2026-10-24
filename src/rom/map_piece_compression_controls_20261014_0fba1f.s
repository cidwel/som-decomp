.setcpu "65816"
.segment "CODE"
.org $BA1F
map_control_0fba1f:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
