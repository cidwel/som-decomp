.setcpu "65816"
.segment "CODE"
.org $8B88
map_control_0f8b88:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
