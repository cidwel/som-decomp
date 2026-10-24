.setcpu "65816"
.segment "CODE"
.org $9DAA
map_control_0d9daa:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
