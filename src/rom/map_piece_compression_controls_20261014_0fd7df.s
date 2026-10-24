.setcpu "65816"
.segment "CODE"
.org $D7DF
map_control_0fd7df:
    .byte $D7 ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
