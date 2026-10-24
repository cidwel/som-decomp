.setcpu "65816"
.segment "CODE"
.org $F82F
map_control_0df82f:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
