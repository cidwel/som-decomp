.setcpu "65816"
.segment "CODE"
.org $2096
map_control_0d2096:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
