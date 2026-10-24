.setcpu "65816"
.segment "CODE"
.org $84AB
map_control_0f84ab:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
