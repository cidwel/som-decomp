.setcpu "65816"
.segment "CODE"
.org $F8A7
map_control_0cf8a7:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
