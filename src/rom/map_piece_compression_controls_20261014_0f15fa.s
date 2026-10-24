.setcpu "65816"
.segment "CODE"
.org $15FA
map_control_0f15fa:
    .byte $C1 ; same-value copy count/distance
