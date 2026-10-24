.setcpu "65816"
.segment "CODE"
.org $D482
map_control_0fd482:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
