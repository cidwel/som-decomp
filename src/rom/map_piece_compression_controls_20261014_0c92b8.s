.setcpu "65816"
.segment "CODE"
.org $92B8
map_control_0c92b8:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
