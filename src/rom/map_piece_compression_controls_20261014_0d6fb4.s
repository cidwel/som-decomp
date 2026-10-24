.setcpu "65816"
.segment "CODE"
.org $6FB4
map_control_0d6fb4:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
