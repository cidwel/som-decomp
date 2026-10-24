.setcpu "65816"
.segment "CODE"
.org $FD09
map_control_0efd09:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
