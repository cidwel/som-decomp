.setcpu "65816"
.segment "CODE"
.org $F497
map_control_0ff497:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
