.setcpu "65816"
.segment "CODE"
.org $3144
map_control_0d3144:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
