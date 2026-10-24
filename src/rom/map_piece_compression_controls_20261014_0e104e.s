.setcpu "65816"
.segment "CODE"
.org $104E
map_control_0e104e:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $12 ; distance low bit/count
