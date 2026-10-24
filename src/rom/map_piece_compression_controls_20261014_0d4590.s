.setcpu "65816"
.segment "CODE"
.org $4590
map_control_0d4590:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
