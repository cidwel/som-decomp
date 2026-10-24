.setcpu "65816"
.segment "CODE"
.org $5B84
map_control_0f5b84:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
