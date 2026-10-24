.setcpu "65816"
.segment "CODE"
.org $6590
map_control_0f6590:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
