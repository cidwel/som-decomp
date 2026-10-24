.setcpu "65816"
.segment "CODE"
.org $50B5
map_control_0d50b5:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
