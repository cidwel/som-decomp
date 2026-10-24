.setcpu "65816"
.segment "CODE"
.org $9476
map_control_0d9476:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
