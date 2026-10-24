.setcpu "65816"
.segment "CODE"
.org $CC93
map_control_0fcc93:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
