.setcpu "65816"
.segment "CODE"
.org $B619
map_control_0db619:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $F1 ; progressive-copy count
