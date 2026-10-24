.setcpu "65816"
.segment "CODE"
.org $3E43
map_control_0c3e43:
    .byte $D1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
