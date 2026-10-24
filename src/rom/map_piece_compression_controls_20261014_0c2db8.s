.setcpu "65816"
.segment "CODE"
.org $2DB8
map_control_0c2db8:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
