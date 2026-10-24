.setcpu "65816"
.segment "CODE"
.org $3BC4
map_control_0d3bc4:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
