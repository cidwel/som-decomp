.setcpu "65816"
.segment "CODE"
.org $7B3F
map_control_0e7b3f:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
