.setcpu "65816"
.segment "CODE"
.org $5C8E
map_control_0c5c8e:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
