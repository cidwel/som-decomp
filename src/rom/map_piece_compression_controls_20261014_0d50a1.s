.setcpu "65816"
.segment "CODE"
.org $50A1
map_control_0d50a1:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
