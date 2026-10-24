.setcpu "65816"
.segment "CODE"
.org $6855
map_control_0d6855:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
