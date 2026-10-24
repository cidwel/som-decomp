.setcpu "65816"
.segment "CODE"
.org $DAED
map_control_0fdaed:
    .byte $C1 ; same-value copy count/distance
