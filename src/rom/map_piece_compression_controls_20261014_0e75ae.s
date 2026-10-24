.setcpu "65816"
.segment "CODE"
.org $75AE
map_control_0e75ae:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
