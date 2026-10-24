.setcpu "65816"
.segment "CODE"
.org $37EE
map_control_0f37ee:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
