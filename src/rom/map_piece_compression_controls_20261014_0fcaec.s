.setcpu "65816"
.segment "CODE"
.org $CAEC
map_control_0fcaec:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
