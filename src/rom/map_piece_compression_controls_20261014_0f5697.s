.setcpu "65816"
.segment "CODE"
.org $5697
map_control_0f5697:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
