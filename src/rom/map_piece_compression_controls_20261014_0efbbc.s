.setcpu "65816"
.segment "CODE"
.org $FBBC
map_control_0efbbc:
    .byte $D1 ; same-value copy count/distance
