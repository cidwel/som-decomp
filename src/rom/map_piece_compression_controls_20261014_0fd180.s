.setcpu "65816"
.segment "CODE"
.org $D180
map_control_0fd180:
    .byte $C6 ; same-value copy count/distance
