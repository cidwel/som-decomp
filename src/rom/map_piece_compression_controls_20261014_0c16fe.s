.setcpu "65816"
.segment "CODE"
.org $16FE
map_control_0c16fe:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
