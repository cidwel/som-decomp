.setcpu "65816"
.segment "CODE"
.org $3776
map_control_0f3776:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
