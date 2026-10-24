.setcpu "65816"
.segment "CODE"
.org $2437
map_control_0e2437:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
