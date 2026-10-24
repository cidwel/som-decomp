.setcpu "65816"
.segment "CODE"
.org $47FC
map_control_0d47fc:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
