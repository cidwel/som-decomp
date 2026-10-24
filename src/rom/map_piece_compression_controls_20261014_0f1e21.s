.setcpu "65816"
.segment "CODE"
.org $1E21
map_control_0f1e21:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
