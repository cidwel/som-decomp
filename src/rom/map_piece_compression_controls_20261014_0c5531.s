.setcpu "65816"
.segment "CODE"
.org $5531
map_control_0c5531:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
