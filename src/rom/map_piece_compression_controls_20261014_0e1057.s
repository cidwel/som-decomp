.setcpu "65816"
.segment "CODE"
.org $1057
map_control_0e1057:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $0F ; distance low bit/count
