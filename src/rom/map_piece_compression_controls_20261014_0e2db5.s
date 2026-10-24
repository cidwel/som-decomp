.setcpu "65816"
.segment "CODE"
.org $2DB5
map_control_0e2db5:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
