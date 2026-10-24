.setcpu "65816"
.segment "CODE"
.org $9D9D
map_control_0d9d9d:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
