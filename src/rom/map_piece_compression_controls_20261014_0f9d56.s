.setcpu "65816"
.segment "CODE"
.org $9D56
map_control_0f9d56:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
