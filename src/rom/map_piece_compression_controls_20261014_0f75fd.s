.setcpu "65816"
.segment "CODE"
.org $75FD
map_control_0f75fd:
    .byte $C5 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
