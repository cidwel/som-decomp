.setcpu "65816"
.segment "CODE"
.org $3A40
map_control_0f3a40:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
