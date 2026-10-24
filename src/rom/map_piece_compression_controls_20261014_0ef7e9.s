.setcpu "65816"
.segment "CODE"
.org $F7E9
map_control_0ef7e9:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
