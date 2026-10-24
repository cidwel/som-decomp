.setcpu "65816"
.segment "CODE"
.org $14FA
map_control_0f14fa:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
