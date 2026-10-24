.setcpu "65816"
.segment "CODE"
.org $7EC6
map_control_0d7ec6:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
