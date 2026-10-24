.setcpu "65816"
.segment "CODE"
.org $703B
map_control_0f703b:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
