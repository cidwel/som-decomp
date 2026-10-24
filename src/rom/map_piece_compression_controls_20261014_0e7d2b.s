.setcpu "65816"
.segment "CODE"
.org $7D2B
map_control_0e7d2b:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
