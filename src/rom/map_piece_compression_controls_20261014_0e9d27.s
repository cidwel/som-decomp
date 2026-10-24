.setcpu "65816"
.segment "CODE"
.org $9D27
map_control_0e9d27:
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
