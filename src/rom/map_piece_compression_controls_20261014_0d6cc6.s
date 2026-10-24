.setcpu "65816"
.segment "CODE"
.org $6CC6
map_control_0d6cc6:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
