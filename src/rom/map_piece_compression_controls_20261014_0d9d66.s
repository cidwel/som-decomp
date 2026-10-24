.setcpu "65816"
.segment "CODE"
.org $9D66
map_control_0d9d66:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
