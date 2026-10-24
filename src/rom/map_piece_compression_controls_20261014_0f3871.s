.setcpu "65816"
.segment "CODE"
.org $3871
map_control_0f3871:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
