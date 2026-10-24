.setcpu "65816"
.segment "CODE"
.org $10F4
map_control_0d10f4:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
