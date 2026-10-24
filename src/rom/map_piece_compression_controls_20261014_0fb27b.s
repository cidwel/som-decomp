.setcpu "65816"
.segment "CODE"
.org $B27B
map_control_0fb27b:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
