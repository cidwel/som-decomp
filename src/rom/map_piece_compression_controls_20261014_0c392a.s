.setcpu "65816"
.segment "CODE"
.org $392A
map_control_0c392a:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
