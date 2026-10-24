.setcpu "65816"
.segment "CODE"
.org $CA72
map_control_0fca72:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
