.setcpu "65816"
.segment "CODE"
.org $9027
map_control_0f9027:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
