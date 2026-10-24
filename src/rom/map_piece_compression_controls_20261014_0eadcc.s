.setcpu "65816"
.segment "CODE"
.org $ADCC
map_control_0eadcc:
    .byte $C5 ; same-value copy count/distance
