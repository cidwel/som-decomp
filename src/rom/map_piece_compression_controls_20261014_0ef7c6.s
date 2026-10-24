.setcpu "65816"
.segment "CODE"
.org $F7C6
map_control_0ef7c6:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
