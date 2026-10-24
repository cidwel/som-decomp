.setcpu "65816"
.segment "CODE"
.org $5A93
map_control_0e5a93:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
