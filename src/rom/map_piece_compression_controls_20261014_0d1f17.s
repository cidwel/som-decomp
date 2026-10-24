.setcpu "65816"
.segment "CODE"
.org $1F17
map_control_0d1f17:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
