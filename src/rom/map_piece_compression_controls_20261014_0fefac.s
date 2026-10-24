.setcpu "65816"
.segment "CODE"
.org $EFAC
map_control_0fefac:
    .byte $C2 ; same-value copy count/distance
