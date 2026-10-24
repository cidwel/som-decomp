.setcpu "65816"
.segment "CODE"
.org $0F09
map_control_0f0f09:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
