.setcpu "65816"
.segment "CODE"
.org $5D30
map_control_0e5d30:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
