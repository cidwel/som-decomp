.setcpu "65816"
.segment "CODE"
.org $B394
map_control_0eb394:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
