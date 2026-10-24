.setcpu "65816"
.segment "CODE"
.org $E637
map_control_0de637:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
