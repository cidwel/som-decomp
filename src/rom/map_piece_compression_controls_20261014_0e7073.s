.setcpu "65816"
.segment "CODE"
.org $7073
map_control_0e7073:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
