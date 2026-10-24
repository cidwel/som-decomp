.setcpu "65816"
.segment "CODE"
.org $B196
map_control_0db196:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
