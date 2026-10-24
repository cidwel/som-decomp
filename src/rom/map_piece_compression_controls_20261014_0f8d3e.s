.setcpu "65816"
.segment "CODE"
.org $8D3E
map_control_0f8d3e:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
