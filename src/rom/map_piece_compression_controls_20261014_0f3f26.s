.setcpu "65816"
.segment "CODE"
.org $3F26
map_control_0f3f26:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $34 ; distance low bit/count
