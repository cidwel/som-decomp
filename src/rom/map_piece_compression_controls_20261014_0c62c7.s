.setcpu "65816"
.segment "CODE"
.org $62C7
map_control_0c62c7:
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
