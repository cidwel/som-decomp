.setcpu "65816"
.segment "CODE"
.org $8E3F
map_control_0c8e3f:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
