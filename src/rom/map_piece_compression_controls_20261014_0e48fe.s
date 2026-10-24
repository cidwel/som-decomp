.setcpu "65816"
.segment "CODE"
.org $48FE
map_control_0e48fe:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
