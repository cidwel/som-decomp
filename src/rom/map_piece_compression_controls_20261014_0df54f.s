.setcpu "65816"
.segment "CODE"
.org $F54F
map_control_0df54f:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
