.setcpu "65816"
.segment "CODE"
.org $FBDD
map_control_0ffbdd:
    .byte $C1 ; same-value copy count/distance
