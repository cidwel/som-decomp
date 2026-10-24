.setcpu "65816"
.segment "CODE"
.org $B0AD
map_control_0eb0ad:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
