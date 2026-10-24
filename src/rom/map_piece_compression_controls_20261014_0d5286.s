.setcpu "65816"
.segment "CODE"
.org $5286
map_control_0d5286:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
