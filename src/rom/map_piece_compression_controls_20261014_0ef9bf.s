.setcpu "65816"
.segment "CODE"
.org $F9BF
map_control_0ef9bf:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
