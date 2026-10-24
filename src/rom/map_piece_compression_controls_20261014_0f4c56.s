.setcpu "65816"
.segment "CODE"
.org $4C56
map_control_0f4c56:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
