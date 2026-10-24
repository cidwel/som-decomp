.setcpu "65816"
.segment "CODE"
.org $7242
map_control_0f7242:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
