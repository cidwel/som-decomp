.setcpu "65816"
.segment "CODE"
.org $BB65
map_control_0ebb65:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
