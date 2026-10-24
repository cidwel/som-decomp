.setcpu "65816"
.segment "CODE"
.org $88BD
map_control_0d88bd:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $74 ; distance low bit/count
