.setcpu "65816"
.segment "CODE"
.org $3A44
map_control_0f3a44:
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
