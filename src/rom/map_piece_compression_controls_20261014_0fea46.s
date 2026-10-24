.setcpu "65816"
.segment "CODE"
.org $EA46
map_control_0fea46:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
