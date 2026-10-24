.setcpu "65816"
.segment "CODE"
.org $F12A
map_control_0df12a:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
