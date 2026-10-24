.setcpu "65816"
.segment "CODE"
.org $5649
map_control_0c5649:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
