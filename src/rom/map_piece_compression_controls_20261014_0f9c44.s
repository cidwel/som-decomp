.setcpu "65816"
.segment "CODE"
.org $9C44
map_control_0f9c44:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $F1 ; progressive-copy count
