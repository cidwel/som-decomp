.setcpu "65816"
.segment "CODE"
.org $91BD
map_control_0c91bd:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
