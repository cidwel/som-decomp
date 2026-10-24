.setcpu "65816"
.segment "CODE"
.org $4A8F
map_control_0d4a8f:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
