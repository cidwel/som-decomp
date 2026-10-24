.setcpu "65816"
.segment "CODE"
.org $26BD
map_control_0c26bd:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
