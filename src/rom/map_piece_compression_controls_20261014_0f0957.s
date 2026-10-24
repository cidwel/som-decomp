.setcpu "65816"
.segment "CODE"
.org $0957
map_control_0f0957:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $0E ; distance low bit/count
