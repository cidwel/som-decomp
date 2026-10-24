.setcpu "65816"
.segment "CODE"
.org $98D2
map_control_0e98d2:
    .byte $E8 ; backreference distance high bits
    .byte $B0 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
