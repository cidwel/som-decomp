.setcpu "65816"
.segment "CODE"
.org $691E
map_control_0d691e:
    .byte $F2 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
