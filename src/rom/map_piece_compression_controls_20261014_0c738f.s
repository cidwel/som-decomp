.setcpu "65816"
.segment "CODE"
.org $738F
map_control_0c738f:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
