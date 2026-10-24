.setcpu "65816"
.segment "CODE"
.org $92A4
map_control_0c92a4:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
