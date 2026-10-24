.setcpu "65816"
.segment "CODE"
.org $91CF
map_control_0e91cf:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
