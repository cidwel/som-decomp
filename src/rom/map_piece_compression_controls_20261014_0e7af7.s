.setcpu "65816"
.segment "CODE"
.org $7AF7
map_control_0e7af7:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
