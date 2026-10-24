.setcpu "65816"
.segment "CODE"
.org $FA17
map_control_0efa17:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
