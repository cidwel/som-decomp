.setcpu "65816"
.segment "CODE"
.org $6594
map_control_0c6594:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
