.setcpu "65816"
.segment "CODE"
.org $B2F1
map_control_0fb2f1:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
