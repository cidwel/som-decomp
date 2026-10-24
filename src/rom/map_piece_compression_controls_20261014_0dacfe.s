.setcpu "65816"
.segment "CODE"
.org $ACFE
map_control_0dacfe:
    .byte $C4 ; same-value copy count/distance
