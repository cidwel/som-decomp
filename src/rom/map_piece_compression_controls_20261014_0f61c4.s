.setcpu "65816"
.segment "CODE"
.org $61C4
map_control_0f61c4:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
