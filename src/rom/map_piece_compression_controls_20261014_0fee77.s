.setcpu "65816"
.segment "CODE"
.org $EE77
map_control_0fee77:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
