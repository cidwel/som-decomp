.setcpu "65816"
.segment "CODE"
.org $4895
map_control_0e4895:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
