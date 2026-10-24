.setcpu "65816"
.segment "CODE"
.org $47C9
map_control_0e47c9:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
