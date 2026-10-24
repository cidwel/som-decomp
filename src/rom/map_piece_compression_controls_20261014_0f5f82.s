.setcpu "65816"
.segment "CODE"
.org $5F82
map_control_0f5f82:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4A ; distance low bit/count
