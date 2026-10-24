.setcpu "65816"
.segment "CODE"
.org $E044
map_control_0fe044:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
