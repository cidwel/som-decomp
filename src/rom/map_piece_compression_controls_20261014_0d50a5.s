.setcpu "65816"
.segment "CODE"
.org $50A5
map_control_0d50a5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
