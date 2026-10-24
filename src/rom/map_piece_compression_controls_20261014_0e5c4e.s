.setcpu "65816"
.segment "CODE"
.org $5C4E
map_control_0e5c4e:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
