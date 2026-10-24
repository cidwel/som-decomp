.setcpu "65816"
.segment "CODE"
.org $50A9
map_control_0d50a9:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
