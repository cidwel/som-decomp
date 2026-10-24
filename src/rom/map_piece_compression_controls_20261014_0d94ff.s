.setcpu "65816"
.segment "CODE"
.org $94FF
map_control_0d94ff:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
