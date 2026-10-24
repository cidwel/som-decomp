.setcpu "65816"
.segment "CODE"
.org $ECAF
map_control_0fecaf:
    .byte $D1 ; same-value copy count/distance
