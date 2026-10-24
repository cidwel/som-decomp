.setcpu "65816"
.segment "CODE"
.org $B088
map_control_0db088:
    .byte $C1 ; same-value copy count/distance
