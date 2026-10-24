.setcpu "65816"
.segment "CODE"
.org $56F1
map_control_0f56f1:
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
