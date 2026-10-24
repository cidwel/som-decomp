.setcpu "65816"
.segment "CODE"
.org $5B56
map_control_0f5b56:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
