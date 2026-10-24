.setcpu "65816"
.segment "CODE"
.org $405B
map_control_0e405b:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
