.setcpu "65816"
.segment "CODE"
.org $F564
map_control_0df564:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
