.setcpu "65816"
.segment "CODE"
.org $46B1
map_control_0e46b1:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
