.setcpu "65816"
.segment "CODE"
.org $50B9
map_control_0d50b9:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
