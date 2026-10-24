.setcpu "65816"
.segment "CODE"
.org $8235
map_control_0d8235:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
