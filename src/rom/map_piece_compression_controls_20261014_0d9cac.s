.setcpu "65816"
.segment "CODE"
.org $9CAC
map_control_0d9cac:
    .byte $E8 ; backreference distance high bits
    .byte $9F ; distance low bit/count
