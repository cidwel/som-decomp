.setcpu "65816"
.segment "CODE"
.org $F953
map_control_0ef953:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
