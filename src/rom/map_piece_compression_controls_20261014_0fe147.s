.setcpu "65816"
.segment "CODE"
.org $E147
map_control_0fe147:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
