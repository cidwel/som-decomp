.setcpu "65816"
.segment "CODE"
.org $568A
map_control_0f568a:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
