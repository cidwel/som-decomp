.setcpu "65816"
.segment "CODE"
.org $68E2
map_control_0d68e2:
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
