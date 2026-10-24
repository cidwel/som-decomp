.setcpu "65816"
.segment "CODE"
.org $2979
map_control_0d2979:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
