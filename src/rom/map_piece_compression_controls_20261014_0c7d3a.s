.setcpu "65816"
.segment "CODE"
.org $7D3A
map_control_0c7d3a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
