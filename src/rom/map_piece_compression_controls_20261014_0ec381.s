.setcpu "65816"
.segment "CODE"
.org $C381
map_control_0ec381:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
