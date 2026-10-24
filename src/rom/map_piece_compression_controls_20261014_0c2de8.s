.setcpu "65816"
.segment "CODE"
.org $2DE8
map_control_0c2de8:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
