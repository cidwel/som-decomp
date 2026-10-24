.setcpu "65816"
.segment "CODE"
.org $1322
map_control_0e1322:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
