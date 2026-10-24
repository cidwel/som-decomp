.setcpu "65816"
.segment "CODE"
.org $48B9
map_control_0e48b9:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
