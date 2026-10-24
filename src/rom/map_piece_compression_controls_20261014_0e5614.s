.setcpu "65816"
.segment "CODE"
.org $5614
map_control_0e5614:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
