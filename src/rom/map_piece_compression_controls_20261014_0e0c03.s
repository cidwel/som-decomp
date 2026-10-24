.setcpu "65816"
.segment "CODE"
.org $0C03
map_control_0e0c03:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
