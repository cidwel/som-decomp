.setcpu "65816"
.segment "CODE"
.org $8B3F
map_control_0d8b3f:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
