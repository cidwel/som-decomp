.setcpu "65816"
.segment "CODE"
.org $7383
map_control_0f7383:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
