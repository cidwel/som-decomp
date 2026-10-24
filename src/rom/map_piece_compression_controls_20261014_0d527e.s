.setcpu "65816"
.segment "CODE"
.org $527E
map_control_0d527e:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
