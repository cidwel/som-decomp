.setcpu "65816"
.segment "CODE"
.org $9B81
map_control_0e9b81:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
