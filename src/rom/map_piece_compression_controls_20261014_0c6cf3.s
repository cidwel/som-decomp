.setcpu "65816"
.segment "CODE"
.org $6CF3
map_control_0c6cf3:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
