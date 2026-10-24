.setcpu "65816"
.segment "CODE"
.org $9824
map_control_0d9824:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
