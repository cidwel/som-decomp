.setcpu "65816"
.segment "CODE"
.org $31CB
map_control_0c31cb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
