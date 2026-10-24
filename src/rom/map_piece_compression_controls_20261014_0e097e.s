.setcpu "65816"
.segment "CODE"
.org $097E
map_control_0e097e:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
