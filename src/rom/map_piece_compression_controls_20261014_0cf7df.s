.setcpu "65816"
.segment "CODE"
.org $F7DF
map_control_0cf7df:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
