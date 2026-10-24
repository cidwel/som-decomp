.setcpu "65816"
.segment "CODE"
.org $F677
map_control_0cf677:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
