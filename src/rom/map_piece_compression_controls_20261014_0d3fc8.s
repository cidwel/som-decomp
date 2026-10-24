.setcpu "65816"
.segment "CODE"
.org $3FC8
map_control_0d3fc8:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
