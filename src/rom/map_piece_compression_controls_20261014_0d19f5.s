.setcpu "65816"
.segment "CODE"
.org $19F5
map_control_0d19f5:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
