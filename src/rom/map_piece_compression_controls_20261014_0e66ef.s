.setcpu "65816"
.segment "CODE"
.org $66EF
map_control_0e66ef:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
