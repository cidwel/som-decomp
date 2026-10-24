.setcpu "65816"
.segment "CODE"
.org $077F
map_control_0f077f:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
