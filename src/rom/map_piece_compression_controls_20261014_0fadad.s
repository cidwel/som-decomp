.setcpu "65816"
.segment "CODE"
.org $ADAD
map_control_0fadad:
    .byte $D5 ; same-value copy count/distance
