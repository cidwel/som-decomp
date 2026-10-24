.setcpu "65816"
.segment "CODE"
.org $6CB4
map_control_0d6cb4:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
