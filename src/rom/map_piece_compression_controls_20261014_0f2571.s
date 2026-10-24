.setcpu "65816"
.segment "CODE"
.org $2571
map_control_0f2571:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
