.setcpu "65816"
.segment "CODE"
.org $932D
map_control_0f932d:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
