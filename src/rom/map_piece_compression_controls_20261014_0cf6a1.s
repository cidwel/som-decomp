.setcpu "65816"
.segment "CODE"
.org $F6A1
map_control_0cf6a1:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
