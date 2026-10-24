.setcpu "65816"
.segment "CODE"
.org $F1F7
map_control_0ef1f7:
    .byte $D7 ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
