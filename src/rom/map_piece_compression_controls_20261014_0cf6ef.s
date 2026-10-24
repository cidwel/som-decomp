.setcpu "65816"
.segment "CODE"
.org $F6EF
map_control_0cf6ef:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
