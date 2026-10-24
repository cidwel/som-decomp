.setcpu "65816"
.segment "CODE"
.org $BB8F
map_control_0fbb8f:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
