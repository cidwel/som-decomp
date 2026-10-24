.setcpu "65816"
.segment "CODE"
.org $CBFC
map_control_0ecbfc:
    .byte $D4 ; same-value copy count/distance
