.setcpu "65816"
.segment "CODE"
.org $5DF0
map_control_0f5df0:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
