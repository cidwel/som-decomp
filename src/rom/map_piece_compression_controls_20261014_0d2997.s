.setcpu "65816"
.segment "CODE"
.org $2997
map_control_0d2997:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
