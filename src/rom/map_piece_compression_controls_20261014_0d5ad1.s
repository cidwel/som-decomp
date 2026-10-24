.setcpu "65816"
.segment "CODE"
.org $5AD1
map_control_0d5ad1:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
