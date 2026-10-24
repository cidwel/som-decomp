.setcpu "65816"
.segment "CODE"
.org $1A79
map_control_0d1a79:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
