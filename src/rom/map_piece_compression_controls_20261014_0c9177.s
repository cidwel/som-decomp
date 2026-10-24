.setcpu "65816"
.segment "CODE"
.org $9177
map_control_0c9177:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
