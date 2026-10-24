.setcpu "65816"
.segment "CODE"
.org $5511
map_control_0c5511:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
