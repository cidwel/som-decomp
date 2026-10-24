.setcpu "65816"
.segment "CODE"
.org $8A59
map_control_0d8a59:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
