.setcpu "65816"
.segment "CODE"
.org $3B0C
map_control_0d3b0c:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
