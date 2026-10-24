.setcpu "65816"
.segment "CODE"
.org $0F1F
map_control_0e0f1f:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
