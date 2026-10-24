.setcpu "65816"
.segment "CODE"
.org $DA2B
map_control_0dda2b:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
