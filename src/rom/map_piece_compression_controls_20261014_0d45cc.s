.setcpu "65816"
.segment "CODE"
.org $45CC
map_control_0d45cc:
    .byte $D7 ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
