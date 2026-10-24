.setcpu "65816"
.segment "CODE"
.org $92B6
map_control_0f92b6:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
