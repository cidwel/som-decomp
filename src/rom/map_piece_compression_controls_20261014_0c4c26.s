.setcpu "65816"
.segment "CODE"
.org $4C26
map_control_0c4c26:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
