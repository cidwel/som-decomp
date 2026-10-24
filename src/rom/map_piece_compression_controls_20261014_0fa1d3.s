.setcpu "65816"
.segment "CODE"
.org $A1D3
map_control_0fa1d3:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
