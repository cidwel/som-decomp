.setcpu "65816"
.segment "CODE"
.org $DCEC
map_control_0fdcec:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
