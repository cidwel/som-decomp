.setcpu "65816"
.segment "CODE"
.org $DAAA
map_control_0fdaaa:
    .byte $CB ; same-value copy count/distance
