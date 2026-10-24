.setcpu "65816"
.segment "CODE"
.org $B2CD
map_control_0fb2cd:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
