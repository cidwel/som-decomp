.setcpu "65816"
.segment "CODE"
.org $F98E
map_control_0ef98e:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
