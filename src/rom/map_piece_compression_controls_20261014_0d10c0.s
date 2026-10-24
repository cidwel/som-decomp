.setcpu "65816"
.segment "CODE"
.org $10C0
map_control_0d10c0:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
