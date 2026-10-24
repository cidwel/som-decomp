.setcpu "65816"
.segment "CODE"
.org $5574
map_control_0e5574:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
