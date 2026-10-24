.setcpu "65816"
.segment "CODE"
.org $F2F6
map_control_0cf2f6:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
