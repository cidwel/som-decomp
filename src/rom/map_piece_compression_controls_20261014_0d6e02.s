.setcpu "65816"
.segment "CODE"
.org $6E02
map_control_0d6e02:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
