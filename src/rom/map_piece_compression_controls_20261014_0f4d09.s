.setcpu "65816"
.segment "CODE"
.org $4D09
map_control_0f4d09:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
