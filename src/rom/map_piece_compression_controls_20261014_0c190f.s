.setcpu "65816"
.segment "CODE"
.org $190F
map_control_0c190f:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
