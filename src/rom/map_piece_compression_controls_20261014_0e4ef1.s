.setcpu "65816"
.segment "CODE"
.org $4EF1
map_control_0e4ef1:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
