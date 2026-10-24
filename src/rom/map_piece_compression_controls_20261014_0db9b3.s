.setcpu "65816"
.segment "CODE"
.org $B9B3
map_control_0db9b3:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
