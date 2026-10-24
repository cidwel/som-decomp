.setcpu "65816"
.segment "CODE"
.org $D7C0
map_control_0fd7c0:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
