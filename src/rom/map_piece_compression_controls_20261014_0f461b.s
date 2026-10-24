.setcpu "65816"
.segment "CODE"
.org $461B
map_control_0f461b:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
