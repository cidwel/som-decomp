.setcpu "65816"
.segment "CODE"
.org $4FB6
map_control_0e4fb6:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
