.setcpu "65816"
.segment "CODE"
.org $9617
map_control_0f9617:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
