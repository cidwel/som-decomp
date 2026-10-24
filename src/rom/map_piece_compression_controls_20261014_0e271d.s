.setcpu "65816"
.segment "CODE"
.org $271D
map_control_0e271d:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
