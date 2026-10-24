.setcpu "65816"
.segment "CODE"
.org $F314
map_control_0ef314:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
