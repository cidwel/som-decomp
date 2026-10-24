.setcpu "65816"
.segment "CODE"
.org $3C1C
map_control_0d3c1c:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
