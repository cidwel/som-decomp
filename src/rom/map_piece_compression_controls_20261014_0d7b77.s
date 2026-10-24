.setcpu "65816"
.segment "CODE"
.org $7B77
map_control_0d7b77:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
