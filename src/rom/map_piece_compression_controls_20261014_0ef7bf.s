.setcpu "65816"
.segment "CODE"
.org $F7BF
map_control_0ef7bf:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
