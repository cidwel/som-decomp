.setcpu "65816"
.segment "CODE"
.org $8FD4
map_control_0f8fd4:
    .byte $D7 ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
