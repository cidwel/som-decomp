.setcpu "65816"
.segment "CODE"
.org $4244
map_control_0d4244:
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
