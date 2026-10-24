.setcpu "65816"
.segment "CODE"
.org $98D8
map_control_0e98d8:
    .byte $E8 ; backreference distance high bits
    .byte $B0 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
