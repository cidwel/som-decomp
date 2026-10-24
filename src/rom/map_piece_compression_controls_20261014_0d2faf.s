.setcpu "65816"
.segment "CODE"
.org $2FAF
map_control_0d2faf:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
