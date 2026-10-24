.setcpu "65816"
.segment "CODE"
.org $58E7
map_control_0e58e7:
    .byte $CA ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $D5 ; same-value copy count/distance
