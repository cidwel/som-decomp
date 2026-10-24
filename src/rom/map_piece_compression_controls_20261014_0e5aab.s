.setcpu "65816"
.segment "CODE"
.org $5AAB
map_control_0e5aab:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
