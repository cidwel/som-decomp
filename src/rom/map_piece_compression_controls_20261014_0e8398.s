.setcpu "65816"
.segment "CODE"
.org $8398
map_control_0e8398:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
