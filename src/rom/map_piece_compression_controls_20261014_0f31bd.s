.setcpu "65816"
.segment "CODE"
.org $31BD
map_control_0f31bd:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
