.setcpu "65816"
.segment "CODE"
.org $D10F
map_control_0ed10f:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
