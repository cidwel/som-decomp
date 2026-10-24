.setcpu "65816"
.segment "CODE"
.org $8B9D
map_control_0f8b9d:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
