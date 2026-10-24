.setcpu "65816"
.segment "CODE"
.org $7D7A
map_control_0d7d7a:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
