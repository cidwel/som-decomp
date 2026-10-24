.setcpu "65816"
.segment "CODE"
.org $3A3E
map_control_0e3a3e:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
