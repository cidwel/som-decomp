.setcpu "65816"
.segment "CODE"
.org $4C55
map_control_0d4c55:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
