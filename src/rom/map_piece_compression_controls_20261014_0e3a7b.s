.setcpu "65816"
.segment "CODE"
.org $3A7B
map_control_0e3a7b:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
