.setcpu "65816"
.segment "CODE"
.org $8DCF
map_control_0e8dcf:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
