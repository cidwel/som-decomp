.setcpu "65816"
.segment "CODE"
.org $976E
map_control_0e976e:
    .byte $E2 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
