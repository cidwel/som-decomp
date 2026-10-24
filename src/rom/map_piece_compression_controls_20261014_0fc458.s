.setcpu "65816"
.segment "CODE"
.org $C458
map_control_0fc458:
    .byte $C7 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
