.setcpu "65816"
.segment "CODE"
.org $C979
map_control_0ec979:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
