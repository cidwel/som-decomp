.setcpu "65816"
.segment "CODE"
.org $41F1
map_control_0d41f1:
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
