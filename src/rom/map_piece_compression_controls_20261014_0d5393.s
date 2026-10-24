.setcpu "65816"
.segment "CODE"
.org $5393
map_control_0d5393:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
