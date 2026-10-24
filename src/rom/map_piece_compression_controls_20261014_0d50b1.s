.setcpu "65816"
.segment "CODE"
.org $50B1
map_control_0d50b1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
