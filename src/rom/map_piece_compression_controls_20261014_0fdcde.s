.setcpu "65816"
.segment "CODE"
.org $DCDE
map_control_0fdcde:
    .byte $C3 ; same-value copy count/distance
