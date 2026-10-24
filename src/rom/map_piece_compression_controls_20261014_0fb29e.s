.setcpu "65816"
.segment "CODE"
.org $B29E
map_control_0fb29e:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
