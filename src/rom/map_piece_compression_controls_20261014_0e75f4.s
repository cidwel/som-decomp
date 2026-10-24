.setcpu "65816"
.segment "CODE"
.org $75F4
map_control_0e75f4:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
