.setcpu "65816"
.segment "CODE"
.org $C348
map_control_0ec348:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
