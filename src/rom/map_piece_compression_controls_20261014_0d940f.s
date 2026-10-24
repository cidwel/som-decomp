.setcpu "65816"
.segment "CODE"
.org $940F
map_control_0d940f:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
