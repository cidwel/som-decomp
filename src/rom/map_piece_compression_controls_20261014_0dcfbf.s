.setcpu "65816"
.segment "CODE"
.org $CFBF
map_control_0dcfbf:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
