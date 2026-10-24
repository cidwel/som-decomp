.setcpu "65816"
.segment "CODE"
.org $8ADA
map_control_0d8ada:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
