.setcpu "65816"
.segment "CODE"
.org $D5D3
map_control_0fd5d3:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
