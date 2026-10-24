.setcpu "65816"
.segment "CODE"
.org $F2A6
map_control_0cf2a6:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
