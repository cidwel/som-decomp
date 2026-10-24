.setcpu "65816"
.segment "CODE"
.org $9357
map_control_0f9357:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
