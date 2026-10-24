.setcpu "65816"
.segment "CODE"
.org $19EF
map_control_0e19ef:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
