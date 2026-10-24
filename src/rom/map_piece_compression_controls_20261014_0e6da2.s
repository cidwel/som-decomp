.setcpu "65816"
.segment "CODE"
.org $6DA2
map_control_0e6da2:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
