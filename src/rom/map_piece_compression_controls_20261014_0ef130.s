.setcpu "65816"
.segment "CODE"
.org $F130
map_control_0ef130:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
