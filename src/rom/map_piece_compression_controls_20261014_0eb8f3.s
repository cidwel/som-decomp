.setcpu "65816"
.segment "CODE"
.org $B8F3
map_control_0eb8f3:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $9C ; distance low bit/count
