.setcpu "65816"
.segment "CODE"
.org $8E61
map_control_0e8e61:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
