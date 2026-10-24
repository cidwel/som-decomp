.setcpu "65816"
.segment "CODE"
.org $6521
map_control_0d6521:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
