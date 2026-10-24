.setcpu "65816"
.segment "CODE"
.org $BEDF
map_control_0ebedf:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
