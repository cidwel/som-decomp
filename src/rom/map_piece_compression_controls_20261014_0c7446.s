.setcpu "65816"
.segment "CODE"
.org $7446
map_control_0c7446:
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
