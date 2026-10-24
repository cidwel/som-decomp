.setcpu "65816"
.segment "CODE"
.org $3E28
map_control_0d3e28:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
