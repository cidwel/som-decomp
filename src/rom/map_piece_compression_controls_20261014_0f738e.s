.setcpu "65816"
.segment "CODE"
.org $738E
map_control_0f738e:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
