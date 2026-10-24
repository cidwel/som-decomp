.setcpu "65816"
.segment "CODE"
.org $8902
map_control_0f8902:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
