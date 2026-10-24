.setcpu "65816"
.segment "CODE"
.org $B640
map_control_0eb640:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
