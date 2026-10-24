.setcpu "65816"
.segment "CODE"
.org $5228
map_control_0d5228:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
