.setcpu "65816"
.segment "CODE"
.org $F167
map_control_0cf167:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
