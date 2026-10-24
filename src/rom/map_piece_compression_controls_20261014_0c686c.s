.setcpu "65816"
.segment "CODE"
.org $686C
map_control_0c686c:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
