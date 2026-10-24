.setcpu "65816"
.segment "CODE"
.org $9E43
map_control_0e9e43:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
