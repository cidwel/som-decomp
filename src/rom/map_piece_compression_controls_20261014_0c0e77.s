.setcpu "65816"
.segment "CODE"
.org $0E77
map_control_0c0e77:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $D3 ; row-distance/count
