.setcpu "65816"
.segment "CODE"
.org $7B85
map_control_0e7b85:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
