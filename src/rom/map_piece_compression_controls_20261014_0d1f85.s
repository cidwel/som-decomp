.setcpu "65816"
.segment "CODE"
.org $1F85
map_control_0d1f85:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
