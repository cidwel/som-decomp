.setcpu "65816"
.segment "CODE"
.org $9138
map_control_0d9138:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
