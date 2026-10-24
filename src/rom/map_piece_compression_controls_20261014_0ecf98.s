.setcpu "65816"
.segment "CODE"
.org $CF98
map_control_0ecf98:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
