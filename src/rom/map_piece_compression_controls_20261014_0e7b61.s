.setcpu "65816"
.segment "CODE"
.org $7B61
map_control_0e7b61:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
