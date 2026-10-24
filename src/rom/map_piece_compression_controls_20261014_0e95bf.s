.setcpu "65816"
.segment "CODE"
.org $95BF
map_control_0e95bf:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
