.setcpu "65816"
.segment "CODE"
.org $CCDB
map_control_0eccdb:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
