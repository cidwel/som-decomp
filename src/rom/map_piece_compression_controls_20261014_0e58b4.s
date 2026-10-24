.setcpu "65816"
.segment "CODE"
.org $58B4
map_control_0e58b4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
