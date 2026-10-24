.setcpu "65816"
.segment "CODE"
.org $7C8F
map_control_0d7c8f:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
