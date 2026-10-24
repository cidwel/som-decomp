.setcpu "65816"
.segment "CODE"
.org $5417
map_control_0d5417:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
