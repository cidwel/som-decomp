.setcpu "65816"
.segment "CODE"
.org $431F
map_control_0f431f:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
