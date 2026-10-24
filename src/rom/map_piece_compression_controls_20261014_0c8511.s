.setcpu "65816"
.segment "CODE"
.org $8511
map_control_0c8511:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
