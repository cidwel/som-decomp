.setcpu "65816"
.segment "CODE"
.org $F85C
map_control_0cf85c:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
