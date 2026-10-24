.setcpu "65816"
.segment "CODE"
.org $967D
map_control_0e967d:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
