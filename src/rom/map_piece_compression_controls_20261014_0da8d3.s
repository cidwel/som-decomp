.setcpu "65816"
.segment "CODE"
.org $A8D3
map_control_0da8d3:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
