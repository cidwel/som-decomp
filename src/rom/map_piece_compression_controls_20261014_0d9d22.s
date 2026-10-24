.setcpu "65816"
.segment "CODE"
.org $9D22
map_control_0d9d22:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
