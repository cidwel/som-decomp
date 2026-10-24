.setcpu "65816"
.segment "CODE"
.org $FCBB
map_control_0ffcbb:
    .byte $C3 ; same-value copy count/distance
