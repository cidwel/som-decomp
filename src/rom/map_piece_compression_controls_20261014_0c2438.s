.setcpu "65816"
.segment "CODE"
.org $2438
map_control_0c2438:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
