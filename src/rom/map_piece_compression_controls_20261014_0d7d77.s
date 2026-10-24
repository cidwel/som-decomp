.setcpu "65816"
.segment "CODE"
.org $7D77
map_control_0d7d77:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
