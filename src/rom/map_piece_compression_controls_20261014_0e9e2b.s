.setcpu "65816"
.segment "CODE"
.org $9E2B
map_control_0e9e2b:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
