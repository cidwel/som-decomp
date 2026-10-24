.setcpu "65816"
.segment "CODE"
.org $6687
map_control_0f6687:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
