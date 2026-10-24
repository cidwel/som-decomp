.setcpu "65816"
.segment "CODE"
.org $2928
map_control_0d2928:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
