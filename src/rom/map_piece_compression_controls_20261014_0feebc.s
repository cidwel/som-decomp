.setcpu "65816"
.segment "CODE"
.org $EEBC
map_control_0feebc:
    .byte $C2 ; same-value copy count/distance
