.setcpu "65816"
.segment "CODE"
.org $9CC2
map_control_0d9cc2:
    .byte $E8 ; backreference distance high bits
    .byte $9F ; distance low bit/count
