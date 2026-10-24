.setcpu "65816"
.segment "CODE"
.org $09DB
map_control_0d09db:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
