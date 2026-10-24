.setcpu "65816"
.segment "CODE"
.org $D070
map_control_0fd070:
    .byte $D1 ; same-value copy count/distance
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
