.setcpu "65816"
.segment "CODE"
.org $FAFE
map_control_0dfafe:
    .byte $D2 ; same-value copy count/distance
