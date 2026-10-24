.setcpu "65816"
.segment "CODE"
.org $2DCC
map_control_0c2dcc:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
