.setcpu "65816"
.segment "CODE"
.org $1296
map_control_0e1296:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
