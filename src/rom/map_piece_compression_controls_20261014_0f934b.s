.setcpu "65816"
.segment "CODE"
.org $934B
map_control_0f934b:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
