.setcpu "65816"
.segment "CODE"
.org $0FED
map_control_0e0fed:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
