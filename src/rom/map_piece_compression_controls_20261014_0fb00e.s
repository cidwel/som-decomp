.setcpu "65816"
.segment "CODE"
.org $B00E
map_control_0fb00e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $F1 ; progressive-copy count
