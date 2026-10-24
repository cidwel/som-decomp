.setcpu "65816"
.segment "CODE"
.org $9373
map_control_0e9373:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
