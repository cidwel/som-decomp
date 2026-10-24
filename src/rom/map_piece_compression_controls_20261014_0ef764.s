.setcpu "65816"
.segment "CODE"
.org $F764
map_control_0ef764:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
